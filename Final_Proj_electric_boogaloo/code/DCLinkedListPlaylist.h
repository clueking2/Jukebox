#ifndef DCLINKEDLISTPLAYLIST_H__
#define DCLINKEDLISTPLAYLIST_H__

#include "DCLinkedList.h"
#include <iostream>
#include <string>


using namespace std;

struct node_playlist {
    node_playlist* next;
    node_playlist* prev;
    Playlist* playlist;
};

class DCLinkedListPlaylist {
public:
    DCLinkedListPlaylist();
    ~DCLinkedListPlaylist();
    node_playlist* init_node_playlist(Playlist* playlist);
    string report();
    void append_playlist(Playlist* playlist);
    void append(node_playlist* new_node);
    int size();
    node_playlist* get_top();
    node_playlist* getNodeAtIndex(int index);
    void swapNodes(node_playlist* node1, node_playlist* node2);

private:
    node_playlist* top_ptr_;
    node_playlist* prev_ptr_;

};

#endif // DCLINKEDLISTPLAYLIST_H__

