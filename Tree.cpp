#include "Tree.h"
#include "Session.h"

Tree::Tree(int rootLabel) : node(rootLabel) {
    depth=0;
}

//Copy Constructor Tree
Tree::Tree(const Tree &other) : node(other.node), children() {
    int size = other.children.size();
    for (int i = 0; i < size; i++) {
        children.push_back(other.children.at(i)->clone());
    }
    depth=other.depth;
}

//void Tree::clearChildren() {
//    for(int i=0;i>children.size(); i++) {
//        delete children.at(i);
//    }
//
//}

Tree::~Tree() {
    if(!children.empty()){
        for(int i=0; i<children.size(); i++){
            delete children.at(i);
        }
    }
}


Tree *Tree::createTree(const Session &session, int rootLabel) {
    Tree *currTree;
    if (session.getTreeType() == Cycle) {
        currTree = new CycleTree(rootLabel, 0);
    } else {
        if (session.getTreeType() == MaxRank) {
            currTree = new MaxRankTree(rootLabel);
        } else {
            currTree = new RootTree(rootLabel);
        }
    }
    return currTree;
}


void Tree::addChild(const Tree &child) {
    Tree *newChild = child.clone();
    newChild->depth=depth+1;
    children.push_back(newChild);
}


void Tree::addChild(Tree *child) {
    addChild(*child);
}

//Assignment Operator Tree
Tree &Tree::operator=(const Tree &other) {
    if (&other != this) {
        node = other.node;
        for (int i = 0; i < children.size(); i++) {
            delete children.at(i);
        }
        for (int i = 0; i < other.children.size(); i++) {
            children.push_back(other.children.at(i)->clone());
        }
        depth=other.depth;
    }
    return *this;
}



CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel), currCycle(currCycle) {}

//Copy Constructor CycleTree
CycleTree::CycleTree(const CycleTree &other) : Tree(other), currCycle(other.currCycle) {}

//Assignment Operator CycleTree
CycleTree &CycleTree::operator=(const CycleTree &other) {
    if (&other != this) {
        Tree::operator=(other);
        currCycle = other.currCycle;
    }
    return *this;
}

CycleTree *CycleTree::clone() const { return new CycleTree(*this); }

int CycleTree::traceTree() {
    CycleTree *currTree = this;
    int currNode = node;
    for (int i = 0; i < currCycle; i++) {
        if (children.empty()) {
            return currNode;
        }
        currTree = (CycleTree *) currTree->children.at(0);
        currNode = currTree->node;
    }
    return currNode;
}

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel) {}

//Copy Constructor MaxRankTree
MaxRankTree::MaxRankTree(const MaxRankTree &other) : Tree(other) {}

MaxRankTree *MaxRankTree::clone() const { return new MaxRankTree(*this); }


//Assignment Operator MaxRankTree
MaxRankTree &MaxRankTree::operator=(const MaxRankTree &other) {
    if (&other != this) {
        Tree::operator=(other);
    }
    return *this;
}

int MaxRankTree::traceTree() {
    MaxRankTree *currTree = this;
    MaxRankTree *returnTree=currTree;
    MaxRankTree *tempTree;
    int numOfChildren = currTree->children.size();
    std::stack<MaxRankTree *> s;
    s.push(currTree);
    int index=0;
    while (!s.empty()) {
        for (int i = 0; i < currTree->children.size(); i++) {
            if(((MaxRankTree *) currTree->children.at(i))->children.size()>numOfChildren){
                returnTree=(MaxRankTree *) currTree->children.at(i);
                numOfChildren=returnTree->children.size();
                index=i;
            }
            else{
                if(((MaxRankTree *) currTree->children.at(i))->children.size()==numOfChildren){
                    tempTree=(MaxRankTree *) currTree->children.at(i);
                    if(tempTree->depth<returnTree->depth){
                        returnTree=tempTree;
                        index=i;
                    }
                    else{
                        if(tempTree->depth==returnTree->depth&&i<index){
                            returnTree=tempTree;
                            index=i;
                        }
                    }
                }
            }
            s.push((MaxRankTree*)currTree->children.at(i));
        }
        currTree=s.top();
        s.pop();
    }
    return returnTree->node;

}

RootTree::RootTree(int rootLabel) : Tree(rootLabel) {}

//Copy Constructor RootTree
RootTree::RootTree(const RootTree &other) : Tree(other) {}

//Assignment Operator RootTree
RootTree &RootTree::operator=(const RootTree &other) {
    if (&other != this) {
        Tree::operator=(other);
    }
    return *this;
}

RootTree *RootTree::clone() const { return new RootTree(*this); }

int RootTree::traceTree() {
    return node;
}





