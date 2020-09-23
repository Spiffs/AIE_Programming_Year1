/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>
using namespace std;


BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	while (m_pRoot)
	{
		Remove(m_pRoot->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const
{
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.

void BinaryTree::Insert(TreeNode* a_nValue)
{
	// check if the new node must be set as 
	if (IsEmpty() == true)
	{
		m_pRoot = a_nValue;
	}
	else
	{
		// temp nodes
		TreeNode* pParent = nullptr;
		TreeNode* pCurrent = nullptr;

		bool exists = false;
		pCurrent = m_pRoot;

		while (pCurrent != NULL && !exists)
		{
			pParent = pCurrent;

			if (a_nValue->GetData() < pCurrent->GetData())
				pCurrent = pCurrent->GetLeft();

			else if (a_nValue->GetData() > pCurrent->GetData())
				pCurrent = pCurrent->GetRight();

			else if (a_nValue->GetData() == pCurrent->GetData())
				exists = true;
		}

		TreeNode* pAddition = a_nValue;

		if (!exists)
		{
			if (pAddition->GetData() < pParent->GetData())
				pParent->SetLeft(pAddition);
			else
				pParent->SetRight(pAddition);
		}
	}
}

void BinaryTree::Insert(int a_nValue)
{
	// check if the new node must be set as 
	if (IsEmpty() == true)
	{
		m_pRoot = new TreeNode(a_nValue);
	}
	else
	{
		// temp nodes
		TreeNode* pParent = nullptr;
		TreeNode* pCurrent = nullptr;

		bool exists = false;
		pCurrent = m_pRoot;

		while (pCurrent != NULL && !exists)
		{
			pParent = pCurrent;

			if (a_nValue < pCurrent->GetData())
				pCurrent = pCurrent->GetLeft();

			else if (a_nValue > pCurrent->GetData())
				pCurrent = pCurrent->GetRight();

			else if (a_nValue == pCurrent->GetData())
				exists = true;
		}

		TreeNode* pAddition = new TreeNode(a_nValue);

		if (!exists)
		{
			if (pAddition->GetData() < pParent->GetData())
				pParent->SetLeft(pAddition);
			else
				pParent->SetRight(pAddition);
		}
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent : nullptr;
}

// find node function
bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	ppOutNode = m_pRoot;

	while (ppOutNode != NULL)
	{
		// returns true on found  
		if (a_nSearchValue == ppOutNode->GetData())
		{
			return true;
		}
		else
		{
			ppOutParent = ppOutNode;

			if (a_nSearchValue < ppOutNode->GetData())
			{
				ppOutNode = ppOutParent->GetLeft();
			}
			else
			{
				ppOutNode = ppOutParent->GetRight();
			}
		}
	}

	// if fail, return false
	return false;
}

void BinaryTree::Remove(int a_nValue)
{
	TreeNode* pParent = nullptr;
	TreeNode* pRemove = nullptr;

	if (FindNode(a_nValue, pRemove, pParent))
	{
		TreeNode* pRight = pRemove->GetRight();
		TreeNode* pLeft = pRemove->GetLeft();

		pRemove->SetLeft(nullptr);
		pRemove->SetRight(nullptr);

		if (pRemove == m_pRoot)
		{
			m_pRoot = m_pRoot->GetRight();
		}
		else if (pRemove->GetData() > pParent->GetData())
			pParent->SetRight(nullptr);
		else if (pRemove->GetData() < pParent->GetData())
			pParent->SetLeft(nullptr);

		// insert the left and right back into the equation 
		if (pRight != nullptr)
			Insert(pRight);

		if (pLeft != nullptr)
			Insert(pLeft);


	}

}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
	PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{

	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}