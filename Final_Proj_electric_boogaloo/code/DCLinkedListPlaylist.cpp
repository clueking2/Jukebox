#include "DCLinkedList.h"
#include "Jukebox.h"
#include "DCLinkedListPlaylist.h"
#include <iostream>
#include <string>


// constructor, initialize private class variables
DCLinkedListPlaylist::DCLinkedListPlaylist() {
    // Your code here
    top_ptr_ = nullptr;
    prev_ptr_ = nullptr;

}


// deconstructor
DCLinkedListPlaylist::~DCLinkedListPlaylist() {}


//creates playlist node and sets the pointer
node_playlist* DCLinkedListPlaylist::init_node_playlist(Playlist* playlist) {
    node_playlist* ret = new node_playlist;
    ret->playlist = playlist;
    ret->next = nullptr;
    ret->prev = nullptr;
    return ret;
}


//report function for DCLinkedList Playlists
string DCLinkedListPlaylist::report() {
    string ret= "";
    node_playlist* cursor = top_ptr_;

    //if cursor is NULL, return an empty string
    if (cursor == nullptr) {
        return ret;
    }

    //if top_ptr_ isn't NULL, make a playlist, get the title, and report the songs in that 
    //playlist, and update the cursor
    if (top_ptr_ != nullptr) {
        Playlist* playlist = cursor->playlist;
        ret += playlist->getPlayTitle() + ":" + "\n" + playlist->report_1play() + "\n";
        cursor = cursor->next;
    }

    //while cursor doesn't = top_ptr_, create a playlist, get the title, report the songs 
    //in that playlist, and update the cursor
    while (cursor != top_ptr_) {
        Playlist* playlist = cursor->playlist;
        ret += playlist->getPlayTitle() + ":" + "\n" + playlist->report_1play() + "\n";
        cursor = cursor->next;
    }
    return ret;
}


//append playlist to a node
void DCLinkedListPlaylist::append_playlist(Playlist* playlist) {
    node_playlist* new_node = init_node_playlist(playlist);
    append(new_node);
}


//append function for append_playlist
void DCLinkedListPlaylist::append(node_playlist* new_node) {
    //if top_ptr_ is NULL, update it with a node_playlist pointer and update the pointers 
    //attactched to it
    if (top_ptr_ == nullptr) {
        top_ptr_ = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        //get last node and update the pointers associated with it and the new node
        node_playlist* last_node = top_ptr_->prev;
        last_node->next = new_node;
        new_node->prev = last_node;
        new_node->next = top_ptr_;
        top_ptr_->prev = new_node;
    }
}


//size of DCLinkedList Playlist
int DCLinkedListPlaylist::size() {
    int ret = 0;
    node_playlist* cursor = top_ptr_;

    //if top_ptr_ isn't NULL, update the size and cursor
    if (top_ptr_ != nullptr){
       ret = ret + 1;
       cursor = cursor->next;
    }

    // while cursor isn't top_ptr_, update the size and cursor
    while (cursor != top_ptr_) {
        ret = ret + 1;
        cursor = cursor->next;
    }
    return ret;
}


//returns the top pointer of DCLinkedList Playlist
node_playlist* DCLinkedListPlaylist::get_top() { 
    return top_ptr_; 
}


//get node at the specified index in the DCLinkedListPlaylist 
node_playlist* DCLinkedListPlaylist::getNodeAtIndex(int index) {
    //if index is < 0 OR >= size, return NULL
    if (index < 0 || index >= size()) {
        return nullptr;
    }

    node_playlist* cursor = top_ptr_;
    int counter = 0;

    //if top_ptr_ isn't NULL and counter is < index, update cursor and counter
    if(top_ptr_ != nullptr && counter < index){
        cursor = cursor->next;
        counter++;
    }

    //while cursor isn't top_ptr_ and counter < index, update cursor and counter
    while (cursor != top_ptr_ && counter < index) {
        cursor = cursor->next;
        counter++;
    }
    return cursor;
}


//swap two nodes in the DCLinkedListPlaylist
void DCLinkedListPlaylist::swapNodes(node_playlist* node1, node_playlist* node2) {
    //if the first or second node_playlist pointers are NULL, return from the function
    if (node1 == nullptr || node2 == nullptr) {
        return;
    }

    //create a temp Playlist pointer and swap the two nodes
    Playlist* temp = node1->playlist;
    node1->playlist = node2->playlist;
    node2->playlist = temp;
}
