# Boggle Solver

### Description

Command line boggle solver. Output will depend on file of words provided.

### Program Arguments

```
program.exe file characters
```

File contains list of words to look for. Words must be lowercase and contain only characters. Words that don't meet this requirement or are less then 3 characters long are ignored.

Characters is the boggle board to search. Must contain only alphabetic characters. Length must be the result of a boggle board that has the same width and height. For example, 16 characters for a 4x4 board or 25 characters for a 5x5 board.


### Example (Usage)

```
main.exe words.txt wehosibfc
```

### Example (Output)
```
Count: 31
bosh                bow                 bows                bowse               eof
esc                 fie                 fish                fob                 fobs
foe                 foes                hew                 hews                hic
hie                 hies                his                 ifs                 owe
owes                sci                 sew                 she                 shew
sic                 sob                 sow                 swob                woe
woes
```