# Show the structure of an html/xml document.

Show the structure of an html/xml document without displaying any of the
values. This is useful if you want to get a high level view of the way a
document is organised. Compared to `xml_structure`, `html_structure`
prints the id and class attributes.

## Usage

``` r
xml_structure(x, indent = 2, file = "")

html_structure(x, indent = 2, file = "")
```

## Arguments

- x:

  HTML/XML document (or part there of)

- indent:

  Number of spaces to ident

- file:

  a [connection](https://rdrr.io/r/base/connections.html), or a
  character string naming the file to print to. If `""` (the default),
  `cat` prints to the standard output connection, the console unless
  redirected by [`sink`](https://rdrr.io/r/base/sink.html). If it is
  `"|cmd"`, the output is piped to the command given by `cmd`, by
  opening a pipe connection.

## Examples

``` r
xml_structure(read_xml("<a><b><c/><c/></b><d/></a>"))
#> <a>
#>   <b>
#>     <c>
#>     <c>
#>   <d>

rproj <- read_html(system.file("extdata", "r-project.html", package = "xml2"))
xml_structure(rproj)
#> <html [lang]>
#>   <head>
#>     <meta [charset]>
#>     <meta [http-equiv, content]>
#>     <meta [name, content]>
#>     <title>
#>       {text}
#>     <link [rel, type, href, sizes]>
#>     <link [rel, type, href, sizes]>
#>     {comment}
#>     <link [href, rel]>
#>     <link [href, rel]>
#>     {comment}
#>     {comment}
#>     {comment}
#>   <body>
#>     {text}
#>     <div [class]>
#>       {text}
#>       <div [class]>
#>         {text}
#>         <div [class, role]>
#>           {text}
#>           <div [class]>
#>             {text}
#>             <div [class]>
#>               {text}
#>               <p>
#>                 <a [href]>
#>                   <img [src, alt]>
#>               {text}
#>               <p>
#>                 <small>
#>                   <a [href]>
#>                     {text}
#>               {text}
#>               <h2>
#>                 {text}
#>               {text}
#>               <p>
#>                 <a [href]>
#>                   {text}
#>               {text}
#>               <h2>
#>                 {text}
#>               {text}
#>               <ul>
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>             {text}
#>             <div [class]>
#>               {text}
#>               <h2>
#>                 {text}
#>               {text}
#>               <ul>
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>             {text}
#>             <div [class]>
#>               {text}
#>               <h2>
#>                 {text}
#>               {text}
#>               <ul>
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>             {text}
#>             <div [class]>
#>               {text}
#>               <h2>
#>                 {text}
#>               {text}
#>               <ul>
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>                 <li>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>             {text}
#>           {text}
#>         {text}
#>         <div [class]>
#>           {text}
#>           <h1>
#>             {text}
#>           {text}
#>           <h2 [id]>
#>             {text}
#>           {text}
#>           <p>
#>             {text}
#>             <strong>
#>               <a [href]>
#>                 {text}
#>             {text}
#>             <a [href]>
#>               {text}
#>             {text}
#>           {text}
#>           <p>
#>             {text}
#>             <a [href]>
#>               {text}
#>             {text}
#>           {text}
#>           <h2 [id]>
#>             {text}
#>           {text}
#>           <ul>
#>             <li>
#>               <p>
#>                 <a [href]>
#>                   <strong>
#>                     {text}
#>                 {text}
#>             {text}
#>             <li>
#>               <p>
#>                 <strong>
#>                   {text}
#>                 {text}
#>             {text}
#>             <li>
#>               <p>
#>                 <a [href]>
#>                   <strong>
#>                     {text}
#>                 {text}
#>             {text}
#>             <li>
#>               <p>
#>                 <strong>
#>                   {text}
#>                 {text}
#>             {text}
#>             <li>
#>               <p>
#>                 <strong>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>             {text}
#>             <li>
#>               <p>
#>                 <strong>
#>                   <a [href]>
#>                     {text}
#>                 {text}
#>             {text}
#>           {comment}
#>         {text}
#>       {text}
#>       <div [class]>
#>         {text}
#>       {text}
#>     {text}
#>     {comment}
#>     {text}
#>     <script [src]>
#>     {comment}
#>     <script [src]>
xml_structure(xml_find_all(rproj, ".//p"))
#> [[1]]
#> <p>
#>   <a [href]>
#>     <img [src, alt]>
#> 
#> [[2]]
#> <p>
#>   <small>
#>     <a [href]>
#>       {text}
#> 
#> [[3]]
#> <p>
#>   <a [href]>
#>     {text}
#> 
#> [[4]]
#> <p>
#>   {text}
#>   <strong>
#>     <a [href]>
#>       {text}
#>   {text}
#>   <a [href]>
#>     {text}
#>   {text}
#> 
#> [[5]]
#> <p>
#>   {text}
#>   <a [href]>
#>     {text}
#>   {text}
#> 
#> [[6]]
#> <p>
#>   <a [href]>
#>     <strong>
#>       {text}
#>   {text}
#> 
#> [[7]]
#> <p>
#>   <strong>
#>     {text}
#>   {text}
#> 
#> [[8]]
#> <p>
#>   <a [href]>
#>     <strong>
#>       {text}
#>   {text}
#> 
#> [[9]]
#> <p>
#>   <strong>
#>     {text}
#>   {text}
#> 
#> [[10]]
#> <p>
#>   <strong>
#>     <a [href]>
#>       {text}
#>   {text}
#> 
#> [[11]]
#> <p>
#>   <strong>
#>     <a [href]>
#>       {text}
#>   {text}
#> 

h <- read_html("<body><p id = 'a'></p><p class = 'c d'></p></body>")
html_structure(h)
#> <html>
#>   <body>
#>     <p#a>
#>     <p.c.d>
```
