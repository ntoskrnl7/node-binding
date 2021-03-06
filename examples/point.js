// Copyright (c) 2019 The NodeBinding Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

const binding = require('../bazel-bin/examples/binding.node');

function printPoint(p) {
  console.log(`(${p.x}, ${p.y})`);
}

const p = new binding.Point();
p.x = 1;
p.y = p.x + 2;
printPoint(p);
const p2 = new binding.Point(2, 4);
printPoint(p2);