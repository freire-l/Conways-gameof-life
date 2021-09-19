#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>

  constexpr std::size_t kFramesPerSecond{60};               //  Target refresh rate for the grid
  
  constexpr int kInitial_display_cell_x{80};                //  Initial number of cells to be displayed on both axis                
  constexpr int kInitial_display_cell_y{40};

  constexpr int kScreen_width{1600};                        //  Width and height of the screen, in pixels
  constexpr int kScreen_height{800};

  constexpr int kInitial_offset_x{0};                       //  Initial offset for the grid inside the screen
  constexpr int kInitial_offset_y{0};

  constexpr int kMax_zoom_out_x{120};                       //  Maximun and minimum value for zoom out and zoom in
  constexpr int kMax_zoom_in_y{8};

  constexpr int kNum_cells_x{720};                          //  Total size both dimentions of the grid, in cells
  constexpr int kNum_cells_y{360};

  /*                                                        //  For a bigger grid, just leaving it here for reference, don't try to run it unless you                                                   
  //constexpr int _num_cells_x{2160};                       //  know what you are doing. The program needs adjustments in order to run a bigger grid
  //constexpr int _num_cells_y{1080};                       //  If you manage to run it at a decent speed feel free to send me a pr :)
  */

  const std::string kFilePath{"../Figures/figure"};             //  Helper strings for constructing file paths
  const std::string kFileExt{".txt"};

  void PrintToConsole(std::string message);                 //  Helper Functions for formating messages to the console

#endif