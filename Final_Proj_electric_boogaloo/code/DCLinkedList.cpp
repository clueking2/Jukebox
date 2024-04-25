#include "DCLinkedList.h"
#include "Jukebox.h"
#include <iostream>
#include <string>


// constructor, initialize private class variables
DCLinkedList::DCLinkedList() {
    top_ptr_ = nullptr;
    prev_ptr_ = nullptr;
}


// deconstructor
DCLinkedList::~DCLinkedList() {}


//create a song node and initialize pointers
node* DCLinkedList::init_node(Song* song) {
    node* ret = new node;
    ret->song = song;
    ret->next = nullptr;
    ret->prev = nullptr;
    return ret;
}

//report function for DCLinkedList, mostly for debugging
string DCLinkedList::report() {
    string ret = "";
    node* cursor = top_ptr_;

    //if cursor = NULL, return string ret
    if (cursor == nullptr) {
        return ret;
    }

    //if top_ptr_ isn't NULL update song with cursor, get the title and artist
    //and update the cursor to point to the next item
    if (top_ptr_ != nullptr) {
        Song* song = cursor->song;
        ret += song->getTitle() + " by " + song->getArtist() + "\n";
        cursor = cursor->next;
    }
    //while cursor doesn't equal top_ptr_, update song with cursor, get the title and 
    //artist, then update cursor to point to the next item
    while (cursor != top_ptr_) {
        // Assuming data is a pointer to a Song object
        // Song* song = reinterpret_cast<Song*>(cursor->song);
        Song* song = cursor->song;
        ret += song->getTitle() + " by " + song->getArtist() + "\n";
        cursor = cursor->next;
    }
    return ret;
}


//append song to DCLinkedList of songs
void DCLinkedList::append_song(Song* song) {
    //create a new node pointer and append it to the DCLinkedList
    node* new_node = init_node(song);
    append(new_node);
}


//append function used in append_song
void DCLinkedList::append(node* new_node) {
    //if top_ptr_ is NULL, make top_ptr_ the new node and update its pointers
    if (top_ptr_ == nullptr) {
        top_ptr_ = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        //otherwise, get the last node from top_ptr_->prev and update the pointers 
        //of new_node and the previous one
        node* last_node = top_ptr_->prev; // Get the last node
        last_node->next = new_node;
        new_node->prev = last_node;
        new_node->next = top_ptr_;
        top_ptr_->prev = new_node;
    }
}

//Size of DCLinkedList of songs
int DCLinkedList::size() {
    int ret = 0;
    node* cursor = top_ptr_;

    //if top_ptr_ isn't NULL, update the counter and the cursor
    if (top_ptr_ != nullptr){
       ret = ret + 1;
       cursor = cursor->next;
    }

    //while the cursor isn't top_ptr_ update the counter and the cursor
    while (cursor != top_ptr_) {
        ret = ret + 1;
        cursor = cursor->next;
    }
    return ret;
}


//returns the top pointer of DCLinkedList of songs
node* DCLinkedList::get_top() { 
    return top_ptr_; 
}


//get node at the specified index in the DCLinkedList
node* DCLinkedList::getNodeAtIndex(int index) {
    //if index is < 0 or >= the size of the DCLinkedList, return NULL
    if (index < 0 || index >= size()) {
        return nullptr;
    }

    node* cursor = top_ptr_;
    int counter = 0;

    //if top_ptr_ isn't NULL and counter is < index, update the cursor and counter
    if(top_ptr_ != nullptr && counter < index){
        cursor = cursor->next;
        counter++;
    }

    //while cursor isn't top_ptr_ and the counter < index, update the cursor and counter
    while (cursor != top_ptr_ && counter < index) {
        cursor = cursor->next;
        counter++;
    }
    return cursor;
}


//swap two nodes in the DCLinkedList
void DCLinkedList::swapNodes(node* node1, node* node2) {
    // if the first or second node pointer is NULL, return from the function
    if (node1 == nullptr || node2 == nullptr) {
        return;
    }
    
    //make a temp Song* variable and use it to swap the two nodes
    Song* temp = node1->song;
    node1->song = node2->song;
    node2->song = temp;
}



//Songs

//constructor
Song::Song(string tle, string art){
    title = tle;
    artist = art;
    playing = false;
}


Song::~Song(){}


//toggle play and pause options
void Song::togglePlayPause(){
    playing = !playing;
        if (playing == true) {
            cout << "Song is now playing." << endl;
        } else {
            cout << "Song is now paused." << endl;
        }
}

//get title of song
string Song::getTitle() {
  return title;
}


//get artist of song
string Song::getArtist() {
  return artist;
}



//Playlists

//constructor
Playlist::Playlist(string tle){
  currentSongNode = nullptr;
  songs = DCLinkedList();
  play_title = tle;
} 


// deconstructor,
Playlist::~Playlist() {}


//get playlist title
string Playlist::getPlayTitle(){
    return play_title;
}


//returns string of playlists of songs
string Playlist::report_1play(){
    string ret;
    ret += songs.report();
    return ret;
}


//returns the previous song node in the playlist
node* Playlist::getPreviousSong() {
    //if the currentSongNode is NULL, print message and return NULL
    if (currentSongNode == nullptr) {
        cout << "No song is currently playing." << endl;
        return nullptr;
    }

    //make a node pointer (cursor) and set it to the previous currentSongNode
    //if cursor is NULL, print message and return NULL
    node* cursor = currentSongNode->prev;
    if (cursor == nullptr) {
        cout << "No previous song available." << endl;
        return nullptr;
    }
    //update currentSongNode with cursor
    currentSongNode = cursor;
    return cursor;
}


//add a song to a playlist
void Playlist::addSong(Song* song) {
    //create a newNode for the song
    node* newNode = songs.init_node(song);
    //append the newNode to the song list
    songs.append(newNode);
}


//returns the size of the playlist
int Playlist::Size() {
    return songs.size();
}


//returns first song on a playlist
node* Playlist::get_top() {
    return songs.get_top(); 
}
