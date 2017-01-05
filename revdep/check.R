library("devtools")

res <- revdep_check()
revdep_check_save_summary()
revdep_check_print_problems()
