# Copyright (c) 2010 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
  'targets': [
    {
      'target_name': 'libtess',
      'type': '<(library)',
      'msvs_guid': 'A78DAE58-5A9C-4A10-AEDF-9E2EEC4FB391',
      'sources': [
        'libtess/dict-list.h',
        'libtess/dict.c',
        'libtess/dict.h',
        'libtess/geom.c',
        'libtess/geom.h',
        'libtess/memalloc.c',
        'libtess/memalloc.h',
        'libtess/mesh.c',
        'libtess/mesh.h',
        'libtess/normal.c',
        'libtess/normal.h',
        'libtess/priorityq-heap.h',
        'libtess/priorityq-sort.h',
        'libtess/priorityq.c',
        'libtess/priorityq.h',
        'libtess/render.c',
        'libtess/render.h',
        'libtess/sweep.c',
        'libtess/sweep.h',
        'libtess/tess.c',
        'libtess/tess.h',
        'libtess/tessmono.c',
        'libtess/tessmono.h',
      ],
      'include_dirs': [
        '.',
        'libtess',
      ],
      'all_dependent_settings': {
        'include_dirs': [
          '.',
          'libtess',
        ],
      },
    },
  ],
}

# Local Variables:
# tab-width:2
# indent-tabs-mode:nil
# End:
# vim: set expandtab tabstop=2 shiftwidth=2:

