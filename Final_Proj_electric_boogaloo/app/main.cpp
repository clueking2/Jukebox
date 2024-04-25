#include <iostream>
#include "../code/Jukebox.h"
#include "../code/DCLinkedList.h"
#include "../code/DCLinkedListPlaylist.h"
#include <cassert>


using namespace std;

// make 4 playlists (same structure) for testing
Playlist* make_basic_playlist1(string play_tle)
{
  Playlist* playlist = new Playlist(play_tle);

  Song* s1 = new Song("song1","artist_a");
  Song* s2 = new Song("song2","artist_a");
  Song* s3 = new Song("song3","artist_a");
  Song* s4 = new Song("song4","artist_a");

  playlist->addSong(s1);
  playlist->addSong(s2);
  playlist->addSong(s3);
  playlist->addSong(s4);

  return playlist;
}

Playlist* make_basic_playlist2(string play_tle)
{
  Playlist* playlist = new Playlist(play_tle);

  Song* s1 = new Song("song5","artist_z");
  Song* s2 = new Song("song6","artist_b");
  Song* s3 = new Song("song7","artist_c");
  Song* s4 = new Song("song8","artist_d");

  playlist->addSong(s1);
  playlist->addSong(s2);
  playlist->addSong(s3);
  playlist->addSong(s4);

  return playlist;
}

Playlist* make_basic_playlist3(string play_tle)
{
  Playlist* playlist = new Playlist(play_tle);

  Song* s1 = new Song("song9","artist_e");
  Song* s2 = new Song("song10","artist_f");
  Song* s3 = new Song("song11","artist_g");
  Song* s4 = new Song("song12","artist_h");

  playlist->addSong(s1);
  playlist->addSong(s2);
  playlist->addSong(s3);
  playlist->addSong(s4);

  return playlist;
}

Playlist* make_basic_playlist4(string play_tle)
{
  Playlist* playlist = new Playlist(play_tle);

  Song* s1 = new Song("song13","artist_i");
  Song* s2 = new Song("song14","artist_j");
  Song* s3 = new Song("song15","artist_k");
  Song* s4 = new Song("song16", "artist_l");

  playlist->addSong(s1);
  playlist->addSong(s2);
  playlist->addSong(s3);
  playlist->addSong(s4);

  return playlist;
}

int test_report(){
  // Tests all of Song, all of Node
  // Within DCLinkedList tests append_song, append, size, and report.
  Song* Ts1 = new Song("song1","artist_a");
  Song* Ts2 = new Song("song2","artist_a");
  Song* Ts3 = new Song("song3","artist_a");
  Song* Ts4 = new Song("song4","artist_a");

  DCLinkedList* dcll = new DCLinkedList();


  cout << "size" << endl;
  cout << dcll->size() << endl;

  dcll->append_song(Ts1);
  cout << "Appended first song to empty dcll." << endl;

  cout << "size" << endl;
  cout << dcll->size() << endl;

  cout << dcll->report() << endl;
  dcll->append_song(Ts2);
  cout << "Appended second song to dcll." << endl;
  cout << dcll->report() << endl;
  dcll->append_song(Ts3);
  dcll->append_song(Ts4);
  cout << "Appended third and fourth songs." << endl;
  cout << dcll->report() << endl;


  cout << "size" << endl;
  cout << dcll->size() << endl;

  node* node1 = dcll->getNodeAtIndex(0);
  node* node2 = dcll->getNodeAtIndex(3);
  cout << "swap nodes" << endl;
  dcll->swapNodes(node1, node2);
  cout << dcll->report() << endl;
}

// testing playlists to make sure they are properly set up
int test_playlists_report()
{
  DCLinkedListPlaylist* dcll_play = new DCLinkedListPlaylist();

  Playlist* pl1 = make_basic_playlist1("playlist 1");
  Playlist* pl2 = make_basic_playlist2("playlist 2");
  Playlist* pl3 = make_basic_playlist3("playlist 3");
  Playlist* pl4 = make_basic_playlist4("playlist 4");

  dcll_play->append_playlist(pl1);
  dcll_play->append_playlist(pl2);
  dcll_play->append_playlist(pl3);
  dcll_play->append_playlist(pl4);

  cout << "Printing DCLL Playlist Report" << endl;
  cout << dcll_play->report() << endl;
  cout << "Report has been called." << endl;
} 




int main(){
  
  // test the newly defined test_report and test_playlists_report functions
  test_report();
  test_playlists_report();

  // Do some printing (start of project testing Jukebpx functions)
  cout << "This is the Jukebox Project by Claire Lueking." << endl;

  // Create a Jukebox object
  Jukebox* jukebox = new Jukebox();
  
  // Use test playlists to be playlists for the Jukebox functions
  Playlist* playlist1 = make_basic_playlist1("Playlist 1");
  Playlist* playlist2 = make_basic_playlist2("Playlist 2");
  Playlist* playlist3 = make_basic_playlist3("Playlist 3");
  Playlist* playlist4 = make_basic_playlist4("Playlist 4");

  // Add playlists to the jukebox
  jukebox->addPlaylist(playlist1);
  jukebox->addPlaylist(playlist2);
  jukebox->addPlaylist(playlist3);
  jukebox->addPlaylist(playlist4);
  
  //code output to check if what happened matches what should've happened
  cout << jukebox->report_juke() << endl;

  // Test playPause() function
  cout << "Testing playPause() function:" << endl;
  // Play the first song in the first playlist
  cout << "Playing the first song in the first playlist:" << endl;
  jukebox->skipToFirstTrackOfCurrentPlaylist();
  jukebox->playPause(); 
  cout << jukebox->report_juke() << endl;


  //Pause the current song
  cout << "Pausing the current song:" << endl;
  jukebox->playPause(); 


  // Test skipToNextTrack() function
  cout << "\nTesting skipToNextTrack() function:" << endl;
  // Skip to the next track in the current playlist
  cout << "Skipping to the next track in the current playlist:" << endl;
  jukebox->skipToNextTrack(); 
  cout << jukebox->report_juke() << endl;


  // Test skipToPreviousTrack() function
  cout << "\nTesting skipToPreviousTrack() function:" << endl;
  // Skip to the previous track in the current playlist
  cout << "Skipping to the previous track in the current playlist:" << endl;
  jukebox->skipToPreviousTrack(); 
  cout << jukebox->report_juke() << endl;


  // Test skipToFirstTrackOfNextPlaylist() function
  cout << "\nTesting skipToFirstTrackOfNextPlaylist() function:" << endl;
  // Skip to the first track of the next playlist
  cout << "Skipping to the first track of the next playlist:" << endl;
  jukebox->skipToFirstTrackOfNextPlaylist(); 
  cout << jukebox->report_juke() << endl;


  // Test skipToFirstTrackOfPreviousPlaylist() function
  cout << "\nTesting skipToFirstTrackOfPreviousPlaylist() function:" << endl;
  // Skip to the first track of the previous playlist
  cout << "Skipping to the first track of the previous playlist:" << endl;
  jukebox->skipToFirstTrackOfPreviousPlaylist();
  cout << jukebox->report_juke() << endl;


  // Test rearrangePlaylistOrder() function
  cout << "\nTesting rearrangePlaylistOrder() function:" << endl;

  // Rearrange the order of playlists
  cout << "Rearranging the order of playlists:" << endl;
  jukebox->rearrangePlaylistOrder(0, 1); 
  cout << jukebox->report_juke() << endl;


  // Toggle repeat mode
  cout << "\nToggling repeat mode:" << endl;
  // Initially, repeat should be off
  assert(jukebox->isRepeatOn() == false);
  // Toggle repeat
  cout << "Toggling repeat on:" << endl;
  jukebox->toggleRepeat(); 
  // After toggling, repeat should be on
  assert(jukebox->isRepeatOn() == true);

  //fun message added after all functions passed (ending of tests)
  cout << "\nAll tests passed successfully!" << endl;

  return 0;
}