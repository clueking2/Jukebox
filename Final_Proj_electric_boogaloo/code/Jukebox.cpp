#include "Jukebox.h"
#include "DCLinkedList.h"
#include "DCLinkedListPlaylist.h"
#include <iostream>


using namespace std;

//constructor, initialize private class members
Jukebox::Jukebox() {
  currentSongNode = nullptr;
  repeat = false;
  playlists = new DCLinkedListPlaylist();
  // Initialize current playlist pointer to nullptr
  currentPlaylist = playlists->init_node_playlist(nullptr); 
}


// deconstructor
Jukebox::~Jukebox() {}


// Toggle play/pause of the current song in the current playlist
void Jukebox::playPause() {
    if (currentPlaylist == nullptr) {
        cout << "No playlist is selected." << endl;
        return;
    }

    if (currentSongNode == nullptr) {
        cout << "No song is currently playing." << endl;
        return;
    }

    currentSongNode->song->togglePlayPause();
}


// Skip to the previous track in the current playlist
void Jukebox::skipToPreviousTrack() {
    if (currentPlaylist == nullptr) {
        cout << "No playlist is selected." << endl;
        return;
    }
    //ternary operator statement: if currentSongNode is NULL, 
    //then if currentSongNode->prev is NULL do stuff, otherwise if 1st statement is 
    //false, assign NULL to prevSongNode
    node* prevSongNode = currentSongNode != nullptr ? currentSongNode->prev : nullptr; 
    if (prevSongNode == nullptr) {
        cout << "No previous track available." << endl;
        return;
    }
    // updating currentSongNode to be prevSongNode and start playing currentSongNode
    currentSongNode = prevSongNode;
    startPlayback(currentSongNode);
}


// Skip to the next track in the current playlist
void Jukebox::skipToNextTrack() {
    //check to make playlist is selected and there is a song selected
    if (currentPlaylist == nullptr) {
        cout << "No playlist is selected." << endl;
        return;
    }

    if (currentSongNode == nullptr) {
        cout << "No song is currently playing." << endl;
        return;
    }
    //create a new node pointer (nextSongNode) that points to next song in playlist
    node* nextSongNode = currentSongNode->next;
    if (nextSongNode == nullptr) {
        cout << "No next track available." << endl;
        return;
    }
    //update currentSongNode to be nextSongNode and then play the current song
    currentSongNode = nextSongNode;
    startPlayback(currentSongNode);
}


// Skip to the first track of the current playlist
void Jukebox::skipToFirstTrackOfCurrentPlaylist() {
    //make sure there is not a current playlist, then prints message
    if (currentPlaylist == nullptr) {
        cout << "No playlist is selected." << endl;
        return;
    }
    //makes sure that the current playlist size is 0, then prints message
    if (currentPlaylist->playlist->Size() == 0) {
        cout << "Current playlist is empty." << endl;
        return;
    }
    //updates currentSongNode to first track and plays the track
    currentSongNode = currentPlaylist->playlist->get_top();
    startPlayback(currentSongNode);
}


// Skip to the first track of the previous playlist
void Jukebox::skipToFirstTrackOfPreviousPlaylist() {
    //if no current playlist, print message
    if (currentPlaylist == nullptr)
    {
        cout << "No Current Playlist." << endl;
        return;
    }
    //if there is no previous playlist, print message
    if (currentPlaylist->prev == nullptr)
    {
        cout << "No previous playlist available." << endl;
        return;
    }
    // update current playlist to the previous one, then check to make sure the 
    //size is > 0, then update currentSongNode to the first track of the current    
    //playlist and play track, else print message
    currentPlaylist = currentPlaylist->prev;
    if(currentPlaylist->playlist->Size() > 0){
        currentSongNode = currentPlaylist->playlist->get_top();
        startPlayback(currentSongNode);
    } else{
        cout << "Previous playlist is empty." << endl;
    }
}


// Skip to the first track of the next playlist
void Jukebox::skipToFirstTrackOfNextPlaylist() {
    //no playlist, print stuff
    if (currentPlaylist == nullptr)
    {
        cout << "No Current Playlist." << endl;
        return;
    }
    //no next playlist, print stuff
    if (currentPlaylist->next == nullptr)
    {
        cout << "No next playlist available." << endl;
        return;
    }
    //update currentPlaylist to the next one and if the size of that is > 0, 
    //update currentSongNode to the first track of the current playlist and play it
    //otherwise, print a message
    currentPlaylist = currentPlaylist->next;
    if (currentPlaylist->playlist->Size() > 0){
        currentSongNode = currentPlaylist->playlist->get_top();
        startPlayback(currentSongNode);
    } else{
        cout << "Next playlist is empty." << endl;
    }
}


// Rearrange the order of playlists
void Jukebox::rearrangePlaylistOrder(int index1, int index2) {
    int playlistCount = playlists->size();

    //if first or second index is < 0 OR is greater than playlistCount print message
    if (index1 < 0 || index1 >= playlistCount || index2 < 0 || index2 >= playlistCount) {
        cout << "Invalid playlist indices provided." << endl;
        return;
    }

    //make two node_playlist pointers that get the nodes at indices 1 and 2
    node_playlist* node1 = playlists->getNodeAtIndex(index1);
    node_playlist* node2 = playlists->getNodeAtIndex(index2);

    //swap the two nodes and print message
    playlists->swapNodes(node1, node2);
    cout << "Playlist order rearranged successfully." << endl;
}


// Toggle repeat mode
void Jukebox::toggleRepeat() {
    repeat = !repeat;
    if (repeat == true) {
        cout << "Repeat is ON." << endl;
    } else {
        cout << "Repeat is OFF." << endl;
    }
}


// Check if repeat mode is on
bool Jukebox::isRepeatOn() {
    return repeat;
}

string Jukebox:: report_juke(){
    string ret = "--- Jukebox ---\n";
    //current song and artist
    ret += "\nCurrent Song is: \n";
    ret += currentSongNode->song->getTitle() + "\n";
    ret += "\nBy Artist: \n";
    ret += currentSongNode->song->getArtist() + "\n";
    //current playlist name
    ret += "\nCurrent Playlist is: \n";
    ret += currentPlaylist->playlist->getPlayTitle() + "\n";
    //play/pause status 
    ret += "\nRepeat is:\n";
    if (isRepeatOn() == true) {
        ret+= "ON.\n";
    } else {
        ret += "OFF.\n";
    }
    ret += "---------------\n";
    //report all playlists
    ret += playlists->report();
    return ret;
}


void Jukebox::addPlaylist(Playlist* playlist) {
    // create new node_playlist pointer and add a playlist node to Jukebox
    node_playlist* new_node = playlists->init_node_playlist(playlist);
    addPlaylistNode(new_node);
}


void Jukebox::addPlaylistNode(node_playlist* nodeplay) {
    //add node playlist
    playlists->append(nodeplay);
    // if only 1 thing is in the jukebox, make the current playlist nodeplay and 
    //skip to first track of current playlist
    if (playlists->size() == 1) {
        currentPlaylist = nodeplay;
        skipToFirstTrackOfCurrentPlaylist();
    }
}


void Jukebox::startPlayback(node* songNode) {
    //set currentSongNode to songNode
    currentSongNode = songNode;
    //play the current song
    currentSongNode->song->togglePlayPause();
}
