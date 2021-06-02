/*
 * Escape character => it preserves  the literal value of the next char
 * example : echo "\"" => "
 *			echo "\$PATH" => $PATH
 *
 */

/*
 * Single quotes => preserves the LITERAL value of each character within the quotes.
 * A single quote may not occur between single quotes, even when preceded by a backslash.
 */

/*
 * Double quotes => preserves the literal value of all characters, with the exception of $
 * ` and \'
 *
 */

/*
 * if ESC_char at the end error
 */

//echo "$ "=> $
//echo "$1" => depends
//echo "$1kol">it's like echo "$1" "kol"
//
//"command" => command
