#' Stream Parse XML
#'
#' Stream parse XML from a connection interface.
#'
#' @export
#' @param con A connection object
#' @param n number of bytes to read per iteration
#' @param verbose output some info to the console
#' @examples catalog <- xml_parse_con(url("http://www.xmlfiles.com/examples/cd_catalog.xml"))
#' yeastxml <- system.file("examples/yeast_small-01.xml", package= "XML")
#' if(file.exists(yeastxml))
#'   yeast <- xml_parse_con(file(yeastxml))
xml_parse_con <- function(con, n = 1000, verbose = TRUE){
  stopifnot(is(con, "connection"))
  if(!isOpen(con)){
    open(con, "rb")
    on.exit(close(con))
  }

  # Init new push parser
  p <- new_push_parser("myparser");
  if(verbose)
    cat("Parsing...")

  # Read from the connection until it is empty
  while(length(buf <- readBin(con, raw(), n))){
    feed_push_parser_raw(p, buf)
    if(verbose)
      cat(".")
  }

  # Close the parser
  close_push_parser(p)
  if(verbose)
    cat("done!\n")
  xml_doc(get_push_parser_doc(p))
}
