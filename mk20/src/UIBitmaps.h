/*
 * Class holding information about the ui.min file on SD card which encodes
 * all user interface images in a single file. This file is automatically generated
 * by our image tools that take PNGs as input and encode those files and
 * generate this file
 *
 * More Info and documentation:
 * http://www.appfruits.com/2016/11/behind-the-scenes-printrbot-simple-2016/
 *
 * Copyright (c) 2016 Printrbot Inc.
 * Author: Mick Balaban
 * https://github.com/Printrbot/Printrhub
 *
 * Developed in cooperation with Phillip Schuster (@appfruits) from appfruits.com
 * http://www.appfruits.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

 #ifndef UI_BITMAPS_H
 #define UI_BITMAPS_H

 #include "framework/core/UIBitmap.h"
 #include "SD.h"

 class UIBitmaps {
 public:
   UIBitmaps();
   ~UIBitmaps();
   UIBitmap btn_back = {0,23500,235,50};
   UIBitmap btn_calibrate = {23500,10416,62,84};
   UIBitmap btn_cancel = {33916,23500,235,50};
   UIBitmap btn_cancel_print = {57416,23500,235,50};
   UIBitmap btn_delete_project = {80916,23500,235,50};
   UIBitmap btn_done = {104416,23500,235,50};
   UIBitmap btn_down = {127916,11200,112,50};
   UIBitmap btn_exit = {139116,5000,50,50};
   UIBitmap btn_filament = {144116,10416,62,84};
   UIBitmap btn_light = {154532,10416,62,84};
   UIBitmap btn_load = {164948,23500,235,50};
   UIBitmap btn_materials = {188448,10416,62,84};
   UIBitmap btn_no = {198864,11200,112,50};
   UIBitmap btn_open = {210064,12000,120,50};
   UIBitmap btn_password = {222064,10416,62,84};
   UIBitmap btn_print_download = {232480,10200,102,50};
   UIBitmap btn_print_start = {242680,10200,102,50};
   UIBitmap btn_save = {252880,23500,235,50};
   UIBitmap btn_select = {276380,23500,235,50};
   UIBitmap btn_settings = {299880,5000,50,50};
   UIBitmap btn_sidebar_blank = {304880,5000,50,50};
   UIBitmap btn_trash = {309880,5000,50,50};
   UIBitmap btn_unload = {314880,23500,235,50};
   UIBitmap btn_up = {338380,11200,112,50};
   UIBitmap btn_update = {349580,10416,62,84};
   UIBitmap btn_upgrade = {359996,23500,235,50};
   UIBitmap btn_wifi = {383496,10416,62,84};
   UIBitmap btn_yes = {393912,11200,112,50};
   UIBitmap downloading_scene = {405112,129600,270,240};
   UIBitmap heating_screen = {534712,129600,270,240};
   UIBitmap hotend = {664312,21780,121,90};
   UIBitmap hotend_offset = {686092,5876,113,26};
   UIBitmap icon_alert = {691968,14792,86,86};
   UIBitmap icon_filament = {706760,14792,86,86};
   UIBitmap job_finish_scene = {721552,73140,230,159};
   UIBitmap light_scene_blue_btn = {794692,6050,55,55};
   UIBitmap light_scene_bulb = {800742,7584,48,79};
   UIBitmap light_scene_bulb_off = {808326,7584,48,79};
   UIBitmap light_scene_green_btn = {815910,6050,55,55};
   UIBitmap light_scene_red_btn = {821960,6050,55,55};
   UIBitmap light_scene_title = {828010,6000,125,24};
   UIBitmap light_scene_yellow_btn = {834010,6050,55,55};
   UIBitmap load_scene = {840060,73140,230,159};
   UIBitmap materials_scene = {913200,129600,270,240};
   UIBitmap scene_empty_project = {1042800,129600,270,240};
   UIBitmap sidebar_blank = {1172400,19000,50,190};
   UIBitmap sidebar_calibrate = {1191400,19000,50,190};
   UIBitmap sidebar_downloading = {1210400,19000,50,190};
   UIBitmap sidebar_filament = {1229400,19000,50,190};
   UIBitmap sidebar_firmware = {1248400,19000,50,190};
   UIBitmap sidebar_jobs = {1267400,19000,50,190};
   UIBitmap sidebar_light = {1286400,19000,50,190};
   UIBitmap sidebar_materials = {1305400,19000,50,190};
   UIBitmap sidebar_password = {1324400,19000,50,190};
   UIBitmap sidebar_printing = {1343400,19000,50,190};
   UIBitmap sidebar_project = {1362400,19000,50,190};
   UIBitmap sidebar_settings = {1381400,19000,50,190};
   UIBitmap sidebar_update = {1400400,19000,50,190};
   UIBitmap sidebar_wifi = {1419400,19000,50,190};
   UIBitmap splash = {1438400,153600,320,240};
   UIBitmap unload_scene = {1592000,129600,270,240};
   UIBitmap upgrade_scene = {1721600,73140,230,159};
   UIBitmap upgrading_scene = {1794740,129600,270,240};

 };


 #endif
