
#include <iostream>
#include "Map.h"
#include <string>
#include <vector>
#include "Polynom.h"

using std::iostream;
using std::string;

//template<class T1, class T2>
//void Map::setOutput(int key, int output)
//{
//    double sinkey = sin(key);
//
//    BinaryTree*cur = root;
//
//    if (root == NULL)
//    {
//        root = new BinaryTree;
//        root->key = sinkey;
//        root->output = output;
//        root->left = root->right = 0;
//    }
//    else
//    {
//        while ((cur->right || sinkey <= cur->key)&&(cur->left || sinkey > cur->key))
//        {
//            if (sinkey > cur->key)
//                cur = cur->right;
//            else
//                cur = cur->left;
//        }
//        if (sinkey > cur->key)
//        {
//            cur->right = new BinaryTree;
//            cur->right->output = output;
//            cur->right->right = cur->right->left = 0;
//            cur->right->key = sinkey;
//            cur->right->parent = cur;
//            return;
//        }
//        if (sinkey <= cur->key)
//        {
//            cur->left = new BinaryTree;
//            cur->left->output = output;
//            cur->left->right = cur->left->left = 0;
//            cur->left->key = sinkey;
//            cur->left->parent = cur;
//        }
//    }
//}
//
//template<class T1, class T2>
//int Map::getOutput(int key)
//{
//    double sinkey = sin(key);
//
//    int n = 0;
//    BinaryTree*cur = root;
//
//    while (cur)
//    {
//        if (sinkey > cur->key)
//        {
//            cur = cur->right;
//        }
//        else
//            if (sinkey < cur->key)
//            {
//                cur = cur->left;
//            }
//            else
//                if (cur->key == sinkey)
//                {
//                    n++;
//                    if (n > 0)
//                    {
//                        return cur->output;
//                    }
//                }
//    }
//    if (n == 0) return 0;
//}
//
//template<class T1, class T2>
//void Map::setVariable(string variable, int value)
//{
//    Variables*cur = var_root;
//
//    if (var_root == NULL)
//    {
//        var_root = new Variables;
//        var_root->variable = variable;
//        var_root->value = value;
//        var_root->left = var_root->right = 0;
//        var_root->parent = 0;
//    }
//    else
//    {
//        while (cur != NULL*/(cur->right || variable <= cur->variable)&&(cur->left || variable > cur->variable))
//        {
//            if (variable > cur->variable)
//            {
//                cur = cur->right;
//            }
//            else
//                cur = cur->left;
//        }
//        if (variable > cur->variable)
//        {
//            cur->right = new Variables;
//            cur->right->value = value;
//            cur->right->right = cur->right->left = 0;
//            cur->right->variable = variable;
//            cur->right->parent = cur;
//            return;
//        }
//        if (variable <= cur->variable)
//        {
//            cur->left = new Variables;
//            cur->left->value = value;
//            cur->left->right = cur->left->left = 0;
//            cur->left->variable = variable;           
//            cur->left->parent = cur;
//        }
//    }
//}
//
//template<class T1, class T2>
//int Map::getVariable(string variable)
//{
//    int n = 0;
//    Variables*cur = var_root;
//
//    while (cur)
//    {
//        if (variable > cur->variable)
//        {
//            cur = cur->right;
//        }
//        else
//            if (variable < cur->variable)
//            {
//                cur = cur->left;
//            }
//            else
//                if (cur->variable == variable)
//                {
//                    n++;
//                    return cur->value;
//                }
//    }
//    if (n == 0) return 0;
//}