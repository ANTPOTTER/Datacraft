# Datacraft
A small barely functional programming language for minecraft datapacks.

# Syntax
## Required Code
### Version
you must somewhere in your code define the version, it should be written in the following style:
`version = 1.20.4;` 
Currently accepted versions include:
`1.20.4`, `1.20.5`

### Relative Coordinates
along with the version you must define an anchor, if not defined it will default to ~ ~ ~, but you can make it a different location, for example `anchor = ~10 ~10 ~-10;` all positive and negative numbers are handled for now.

if relative coordinates are used in your code, they will be done relative to your anchor, for example with the above anchor, if you use `~-1 ~-2 ~9` it will execute as `~9 ~8 ~-1` relative to where the anchor was placed down.

## If else Statements
An If Else statement can be defined with the below code. There is currently no support for Else if loops, this will be added later
```
if 1 == 1 {
  
}
else {

}
```

## Variables
there are currently three variable types, `int`, `str`, and `code`. A variable name has to contain no space characters or semi-colons, if one of these is in a variable name it will either cut the variable name off and only accept the first word, and if its a semi-colon, I don't know tbh, its untested :D. 
There is no official support for decimal numbers but my code is poorly written so it might accept a decimal anyway, I also made code a variable type instead of making functions because.
Below is an integer, string, and if else statement defined in variables, appropriately named.
```
var Integer_Name = int(19)
var String_Name = str(This is a string)
var Code_Name = code(
  if 1 == 1 {
    
  }
  else {
  
  }
)
```
Strings do not have "" around them, it's contained by `str()`, so you need to use a \ before every ) in the string. There is no support for multiline Strings.

## Outputting text
You can write to the minecraft chat with `print()`. inside a print statement. `print(str(This is a string))` is the propor syntax for strings, the same applies for integers.

## Delay
Delay can be created with `sleep()`, a number must be put in the brackets, if no number is used it will default to 1. you may also choose between ticks, real-life seconds, real-life hours, and ingame days. This is chosen with t (which can be ommited), s, h, d in that respective order. 

## Random Numbers
from version `1.20.4` onwards, `random()` may be used. to pick a random number within 1 to 6, the syntax is `random(1, 6)`

## Attributes
if you have `@const` before a line of code, it will run every single tick.
`@dropless` may be used to make a block not drop an item when broken.
To use both attributes, the syntax is `@const && dropless`

## Range
```
range from ~3 ~3 ~3 to ~-3 ~-3 ~-3 {
  if coordinates == diamond_ore {
    
  }
}
```
Above is a Range loop, containing an if statement that uses the var `coordinates`. A range loop will execute for every coordinate within the supplied range, the `coordinates` variable will change every iteration, starting on the lowest layer, in the north east corner, going west, then going back to the next row and going west again, then doing that for every layer in ascending order. 
if you have `coordinates == diamond_ore;` within a Range loop, it will set those coordinates to a block of diamond ore. 
