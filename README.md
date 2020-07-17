# POP-Project
A simple version control system

### Requirements
Linux OS

parallel

bsdiff

bspatch

gcc compiler(latest version recommended)


### Installation

For required packages run command below:

    sudo apt install parallel bspatch bsdiff

And run:
    
    make


# Main program #

Used "bsdiff" and "bspatch" to make some patches for version control.

Note: does not work for folders !

## How to use ##

This program wrote in C, so you have to use "main" file.

Copy "main" file to the folder that you want to control files and run:

    ./main

### init ###

This command creates a folder for controling the versions of your files.

### status ###

Gives you the information about the files if they are recently made, deleted or modified.

### select ###

To select your file and save your different versions, you have to use select command.

Just use select command and enter your file name(s) between double quotations.
    
    select "file_name1" "file_name2"
    
Or you can select all the files using -all switch:
    
    select -all
    

### unselect ###

To unselect the files run command below as same as select command:

    unselect "file_name" "file.txt"

Or you can unselect all the files using -all switch:

    unselect -all


    
Note: You can skip this command and use select for another file instead.

### commit ###

To commit your file, run this command and put a description for it between double quotatios.

    commit "description of this commit"

### logs ###

If you wanted to see informations about your commits, run this command.

If you had no commits, nothing will shown.

### reset ###

To reset to one of your commits, use reset command and put an id after it (you can see commit IDs in "logs" command).

Note: your main directory will restor exactly as same as to the commit that you entered. You may lose your data.

    reset ID

### stash ###

If you wondered you want to save all of your files and reset to a commit id stash is here :)

You have 2 options:

    stash ID
    
Your folder restor exactly as same as to the commit that you entered and your files will save somewhere else.

    stash pop
    
Your folder will restor exactly as same as to the files that you used stash **in the last time** .

### exit ###

Good Bye (◍•ᴗ•◍)❤


**If you had any question or if you found any bugs, please report me :)**



















