# JukeBox

## Video Walkthrough: https://youtu.be/2facuiI6-k8

## Overview 

A Jukebox is a music-playing machine commonly found in diners and other places. Typically you pay money (or not if it's free) to play a song or several songs. There are usually options to play and pause songs, skip to previous and next tracks, skip to first tracks of current, next, and previous playlists, and to toggle the Jukebox to repeat all the playlists. Each Jukebox is different, so some may have more or less features than the ones outlined here.

## Data Structures
Here, a couple of doubly circularly linked lists are created for songs and playlists within the Jukebox to achieve the functionality mentioned below. These ensure playlists and songs follow a pattern, but the pattern can be adjusted depending the function the user wants to perform.

A linked list consists of nodes with data in them and that are connected by pointers or references that link the nodes together. This aids in dynamic memory allocation and allows quicker insertions and deletions than vecotrs and arrays.

A doubly linked list is a linked list that is bidirectional. This means that instead of pointers pointing just to the next node in the list, there are pointers also pointing to the previous nodes.

A circularly linked list is one that doesn't have a last node that has a pointer to NULL. Instead, the last pointer points back to the first node in the list. Going through the list leads someone to go in a circle when they reach the last node.

Therefore a doubly circularly linked list is a linked list that has bidirectional pointers and loops back onto itself. This is a good choice for a jukebox because many times playlists are repeated as are the songs on those playlists.


## Goals

* Implement a Jukebox with various playlists and songs
* Implement Jukebox functions of:
* Play/Pause Toggle
* Skip to Previous Track
* Skip to Next Track
* Skip to First Track of Current Playlist
* Skip to First Track of Previous Playlist (if currently playing the first track of a playlist)
* Skip to First Track of Next Playlist
* Toggle Jukebox Repeat (if ON, plays first song of first playlist after having already finished last song in the last playlist)


## Instructions To Run
1. Open up the project in VS Code after downloading the project.
2. Go from the folder, Final_Proj_Electric_Boogaloo, and open a terminal. 
3. Open up the main.cpp file.
4. Type "cd build" command into the terminal from within the folder.
5. Type "cmake .." into the terminal command line.
6. Type "make && ./run_app" into the terminal command line to run the tests and look at the output.
