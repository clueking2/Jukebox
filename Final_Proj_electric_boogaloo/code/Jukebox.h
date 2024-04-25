#ifndef JUKEBOX_H__
#define JUKEBOX_H__

#include <string>
#include "DCLinkedList.h"
#include "DCLinkedListPlaylist.h"
#include <iostream>

using namespace std;


class Jukebox {
private:
  DCLinkedListPlaylist* playlists;
  //indicates whether the jukebox should repeat after reaching the end
  bool repeat; 
  node_playlist* currentPlaylist;
  node* currentSongNode;

public:
  // Constructor and destructor
  Jukebox();
  ~Jukebox();

  // Functions to control the jukebox
  string report_juke();
  void addPlaylist(Playlist* playlist);
  void addPlaylistNode(node_playlist* nodeplay);
  void playPause();
  void skipToPreviousTrack();
  void skipToNextTrack();
  void skipToFirstTrackOfCurrentPlaylist();
  void skipToFirstTrackOfPreviousPlaylist();
  void skipToFirstTrackOfNextPlaylist();
  void rearrangePlaylistOrder(int index1, int index2);
  void toggleRepeat();
  bool isRepeatOn();
  void startPlayback(node* songNode);

};

#endif // JUKEBOX_H__
