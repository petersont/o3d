# Copyright (c) 2009 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
  'variables': {
    'chromium_code': 0,
  },
  'includes': [
    '../../o3d/build/common.gypi',
  ],
  'targets': [
    {
      'target_name': 'antlr3c',
      'type': '<(library)',
      'variables': {
        'antlrcsrc': 'runtime/C',
      },
      'sources': [
        '<(antlrcsrc)/src/antlr3baserecognizer.c',
        '<(antlrcsrc)/src/antlr3basetree.c',
        '<(antlrcsrc)/src/antlr3basetreeadaptor.c',
        '<(antlrcsrc)/src/antlr3bitset.c',
        '<(antlrcsrc)/src/antlr3collections.c',
        '<(antlrcsrc)/src/antlr3commontoken.c',
        '<(antlrcsrc)/src/antlr3commontree.c',
        '<(antlrcsrc)/src/antlr3commontreeadaptor.c',
        '<(antlrcsrc)/src/antlr3commontreenodestream.c',
        '<(antlrcsrc)/src/antlr3convertutf.c',
        '<(antlrcsrc)/src/antlr3cyclicdfa.c',
        '<(antlrcsrc)/src/antlr3debughandlers.c',
        '<(antlrcsrc)/src/antlr3encodings.c',
        '<(antlrcsrc)/src/antlr3exception.c',
        '<(antlrcsrc)/src/antlr3filestream.c',
        '<(antlrcsrc)/src/antlr3inputstream.c',
        '<(antlrcsrc)/src/antlr3intstream.c',
        '<(antlrcsrc)/src/antlr3lexer.c',
        '<(antlrcsrc)/src/antlr3parser.c',
        '<(antlrcsrc)/src/antlr3rewritestreams.c',
        '<(antlrcsrc)/src/antlr3string.c',
        '<(antlrcsrc)/src/antlr3stringstream.c',
        '<(antlrcsrc)/src/antlr3tokenstream.c',
        '<(antlrcsrc)/src/antlr3treeparser.c',
        '<(antlrcsrc)/src/antlr3ucs2inputstream.c',
      ],
      'include_dirs': [
        '<(antlrcsrc)/include',
      ],
      'direct_dependent_settings': {
        'include_dirs': [
          '<(antlrcsrc)/include',
        ],
      },
      'defines': [
        'ANTLR3_NO_DEBUGGER',
        'HAVE_CTYPE_H',
      ],
    },
  ],
}
