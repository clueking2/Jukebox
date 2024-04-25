#ifndef DCLINKEDLIST_H__
#define DCLINKEDLIST_H__

#include <iostream>
#include <string>


using namespace std;


//forward declaration of Playlist class to resolve circular dependency
class Playlist;


class Song {
private:
  string title;
  string artist;
  bool playing;

public:
  Song(string tle, string art);
  ~Song();
  void togglePlayPause();
  string getTitle();
  string getArtist();

};


struct node {
  node* next;
  node* prev;
  Song* song;

};


class DCLinkedList {
public:
  DCLinkedList();
  ~DCLinkedList();
  node* init_node(Song* song);
  string report();
  void append_song(Song* song);
  void append(node* new_node);
  int size();
  node* get_top();
  node* getNodeAtIndex(int index);
  void swapNodes(node* node1, node* node2);

private:
  node* top_ptr_;
  node* prev_ptr_;

};


class Playlist {
private:
  DCLinkedList songs; // Doubly circularly linked list of songs
  node* currentSongNode;
  string play_title;
    
public:
  Playlist(string tle);
  ~Playlist();
  string getPlayTitle();
  node* getPreviousSong();
  node* get_top();
  void addSong(Song* song);
  string report_1play();
  int Size();

};

#endif // DCLINKEDLIST_H__
