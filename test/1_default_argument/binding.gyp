{
  "targets": [
    {
      "target_name": "1_default_argument",
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "sources": ["addon.cc"],
      "include_dirs": [
        "<!@(node -p \"require('../../').include\")",
      ],
      'defines': ['NAPI_DISABLE_CPP_EXCEPTIONS'],
    }
  ]
}