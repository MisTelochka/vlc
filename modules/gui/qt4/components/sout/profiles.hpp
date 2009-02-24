#define NB_PROFILE 12

static const char *const video_profile_name_list[] = {
    "Video - H.264 + AAC",
    "Video - Dirac + AAC",
    "Video - Theora + Vorbis",
    "Video - Theora + Flac",
    "Video - MPEG-4 + AAC",
    "Video - MPEG-2 + MPGA",
    "Video - WMV + WMA",
    "Video - DIV3 + MP3",
    "Audio - Vorbis",
    "Audio - MP3",
    "Audio - AAC",
    "Audio - FLAC",
};
static const char *const video_profile_value_list[] = {
    "ts;1;1;0;h264;800;1;0;0;0;mp4a;128;2;44100;0;0",
    "ts;1;1;0;drac;800;1;0;0;0;mp4a;128;2;44100;0;0",
    "ogg;1;1;0;theo;800;1;0;0;0;vorb;128;2;44100;0;0",
    "ogg;1;1;0;theo;800;1;0;0;0;flac;128;2;44100;0;0",
    "mp4;1;1;0;mp4v;800;1;0;0;0;mp4a;128;2;44100;0;0",
    "ts;1;1;0;mp2v;800;1;0;0;0;mpga;128;2;44100;0;0",
    "asf;1;1;0;WMV2;800;1;0;0;0;wma;128;2;44100;0;0",
    "asf;1;1;0;DIV3;800;1;0;0;0;mp3;128;2;44100;0;0",
    "ogg;0;1;0;0;800;1;0;0;0;vorb;128;2;44100;0;0",
    "raw;0;1;0;0;800;1;0;0;0;mp3;128;2;44100;0;0",
    "mp4;0;1;0;0;800;1;0;0;0;mp4a;128;2;44100;0;0",
    "raw;0;1;0;0;800;1;0;0;0;flac;128;2;44100;0;0",
};

