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
//export MallocStackLogging=1 to test the leaks

//export a=$c for exmaple

//tokenize inside state normal => so I have to handle this case by not separating by spaces
//if befor dollar therr an affectation operator

//export a="echo hey"
//$a => hey  
//"$a" => echo hey : command not found
//=$a =>=echo
//="$a" => =echo hye : command not found

//Assignement is not required
//inside export if there is