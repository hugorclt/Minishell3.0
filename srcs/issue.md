# Lexer

Okay first we have to build a lexer, the lexer is used to build the AST, it will be two important function:
    - peek_token: will return a token_type an enum that list all special token in our shell
    - scan_token: will return (a node of the tree? or just a token) and consume it so the next time we call scan_token it will return the next token in the input prompt, i think scan_token could apply all the transformation process too and should directly return a node containing all infile and outfile necessary for the execution to work.

# Issue

## Major

- [] Lexer: We can't know if we have reached end of line or if we have an error in peek_token and scan_token
    - Solution:
        - We could specify a special token_type to specify when we have reached the end and return NULL if we have an error
            - Drawbacks: Can't think of any for the moment because parsing is not done, but i'm wary of this fix because it's a bit counter intuitive
        - We could return an int and not return token_type -1 should be error and 0, 1, 2, 3, 4 will be token, 5 should be a command and 6 should be the end of line
            - Drawbacks: should be good but if we want to add token later it could be cumbersome

## Minor
- [] Lexer: We have to initiate a tab_array of 6 containing all token ["(", ")", "&&", "||", "|"] and we have to allocate all of them, i prefer to avoid mallocating this but no other choice right now with this implementation
    - Solution:
        - Implement a different way to recognize token like with a forest of if but i'm not sure if this is better than allocating
        - Maybe there is a way to initalize this array on the stack, because each of these string are of fixed size, [1, 1, 2, 2, 1]
- [] Changez le split
