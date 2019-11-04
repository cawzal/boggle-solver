# Boggle Solver

### Description

Command line boggle solver. Output will depend on file of words provided.

### Arguments

```
executable.exe <file-of-words> <characters-to-search>
```

File of words must be lowercase and contain only characters. Words that don't meet this requirement are ignored along with words that are less than 3 characters long. Characters to search provided must also be lowercase and have an appropriate length. This length must be the result of a boggle board that has the same width and height. For example, 16 characters for a 4x4 board or 25 characters for a 5x5 board.

### Example (Building)

```
g++ -o main main.cpp Board.cpp Trie.cpp
```

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