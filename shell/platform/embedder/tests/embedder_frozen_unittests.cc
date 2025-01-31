// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/shell/platform/embedder/embedder.h"
#include "flutter/shell/platform/embedder/tests/embedder_frozen.h"
#include "flutter/testing/testing.h"

namespace flutter {
namespace testing {

// Assert that both types have the same member with the same offset.
// This prevents reordering of "frozen" embedder API struct members.
#define ASSERT_EQ_OFFSET(type1, type2, member) \
  ASSERT_EQ(offsetof(type1, member), offsetof(type2, member))

// New members must not be added to `FlutterSemanticsNode`
// as it would break the ABI of `FlutterSemanticsUpdate`.
// See: https://github.com/flutter/flutter/issues/121176
TEST(EmbedderFrozen, FlutterSemanticsNodeIsFrozen) {
  ASSERT_EQ(sizeof(FlutterSemanticsNode), sizeof(FrozenFlutterSemanticsNode));

  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   struct_size);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, id);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, flags);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, actions);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   text_selection_base);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   text_selection_extent);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   scroll_child_count);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   scroll_index);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   scroll_position);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   scroll_extent_max);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   scroll_extent_min);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, elevation);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, thickness);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, label);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, hint);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, value);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   increased_value);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   decreased_value);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   text_direction);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, rect);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, transform);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   child_count);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   children_in_traversal_order);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   children_in_hit_test_order);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   custom_accessibility_actions_count);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   custom_accessibility_actions);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode,
                   platform_view_id);
  ASSERT_EQ_OFFSET(FlutterSemanticsNode, FrozenFlutterSemanticsNode, tooltip);
}

// New members must not be added to `FlutterSemanticsCustomAction`
// as it would break the ABI of `FlutterSemanticsUpdate`.
// See: https://github.com/flutter/flutter/issues/121176
TEST(EmbedderFrozen, FlutterSemanticsCustomActionIsFrozen) {
  ASSERT_EQ(sizeof(FlutterSemanticsCustomAction),
            sizeof(FrozenFlutterSemanticsCustomAction));

  ASSERT_EQ_OFFSET(FlutterSemanticsCustomAction,
                   FrozenFlutterSemanticsCustomAction, struct_size);
  ASSERT_EQ_OFFSET(FlutterSemanticsCustomAction,
                   FrozenFlutterSemanticsCustomAction, id);
  ASSERT_EQ_OFFSET(FlutterSemanticsCustomAction,
                   FrozenFlutterSemanticsCustomAction, override_action);
  ASSERT_EQ_OFFSET(FlutterSemanticsCustomAction,
                   FrozenFlutterSemanticsCustomAction, label);
  ASSERT_EQ_OFFSET(FlutterSemanticsCustomAction,
                   FrozenFlutterSemanticsCustomAction, hint);
}

}  // namespace testing
}  // namespace flutter
