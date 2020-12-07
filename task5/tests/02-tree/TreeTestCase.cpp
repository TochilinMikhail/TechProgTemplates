//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>

TEST(TreeTestCase, no_path) {
    ASSERT_THROW(GetTree("no_path", true), std::invalid_argument);
    ASSERT_THROW(GetTree("no_path", false), std::invalid_argument);
}

TEST(TreeTestCase, file) {
    boost::filesystem::ofstream file("file");
    ASSERT_THROW(GetTree("file", true), std::invalid_argument);
}

TEST(TreeTestCase, equals) {
    FileNode node1;
    node1.name = "dir1";
    node1.is_dir = true;

    FileNode node2;
    node2.name = "dir1";
    node2.is_dir = true;

    ASSERT_EQ(node1, node2);
}

TEST(TreeTestCase, notEquals1) {
    FileNode node1;
    node1.name = "dir1";
    node1.is_dir = true;

    FileNode node2;
    node2.name = "dir2";
    node2.is_dir = true;

    ASSERT_FALSE(node1 == node2);
}

TEST(TreeTestCase, notEquals2) {
    FileNode node1;
    node1.name = "dir1";
    node1.is_dir = true;

    FileNode node2;
    node2.name = "dir1";
    node2.is_dir = false;

    ASSERT_FALSE(node1 == node2);
}

TEST(TreeTestCase, dirs_only) {
    FileNode node1;
    node1.name = "dir";
    node1.is_dir = true;

    boost::filesystem::create_directory("dir");
    boost::filesystem::ofstream file("dir/file");

    ASSERT_EQ(GetTree("dir", true), node1);
}

TEST(TreeTestCase, not_dirs_only) {
    FileNode node1;
    node1.name = "dir1";
    node1.is_dir = true;
    boost::filesystem::create_directory("dir1");

    FileNode node2;
    node2.name = "dir2";
    node2.is_dir = true;
    node1.children.push_back(node2);
    boost::filesystem::create_directory("dir1/dir2");

    FileNode node3;
    node3.name = "file";
    node3.is_dir = false;
    node1.children.push_back(node3);
    boost::filesystem::ofstream file("dir1/file");

    boost::filesystem::remove_all("dir1/.DS_Store");
    ASSERT_EQ(GetTree("dir1", false), node1);
}


