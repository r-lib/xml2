library("devtools")

res <- revdep_check_resume()
revdep_check_save_summary()
revdep_check_print_problems()
