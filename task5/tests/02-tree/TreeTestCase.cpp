//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

#include <boost/filesystem.hpp>

using boost::filesystem::ofstream;
using boost::filesystem::remove_all;
using boost::filesystem::rename;
using boost::filesystem::create_directory;


void TreeTestCase::SetUp() {

  create_directory("dir");

  create_directory("dir/dir_ch");

  ofstream("dir/file");
}

void TreeTestCase::TearDown() {
  remove_all("dir");
}

TEST_F(TreeTestCase, no_path) {
  ASSERT_THROW(GetTree("dir/no_path", true), std::invalid_argument);
  ASSERT_THROW(GetTree("dir/no_path", false), std::invalid_argument);
}

TEST_F(TreeTestCase, file) {
  ASSERT_THROW(GetTree("dir/file", true), std::invalid_argument);
}

TEST_F(TreeTestCase, equal_1) {
  FileNode node;
  node.name = "dir_ch";
  node.is_dir = true;

  ASSERT_TRUE(GetTree("dir/dir_ch", true) == node);
}

TEST_F(TreeTestCase, equal_2) {
  FileNode node;
  node.name = "dir_ch";
  node.is_dir = true;

  ASSERT_TRUE(GetTree("dir", true).children[0] == node);
}

TEST_F(TreeTestCase, equal_3) {
  FileNode node;
  node.name = "dir";
  node.is_dir = true;
  
  FileNode node_ch;
  node_ch.name = "dir_ch";
  node_ch.is_dir = true;
  node.children.push_back(node_ch);

  ASSERT_TRUE(GetTree("dir", true) == node);
}

TEST_F(TreeTestCase, ch_size_1) {

  ASSERT_TRUE(GetTree("dir", true).children.size() == 1);
}

TEST_F(TreeTestCase, ch_size_2) {

  ASSERT_TRUE(GetTree("dir/dir_ch", true).children.size() == 0);
}

TEST_F(TreeTestCase, ch_size_3) {

  ASSERT_TRUE(GetTree("dir", false).children.size() == 2);
}
