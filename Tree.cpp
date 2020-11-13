#include "Tree.h"
#include "Session.h"
//#include "Graph.h"

Tree::Tree(int rootLabel):node(rootLabel){}
//Copy Constructor Tree
Tree::Tree(const Tree& other):  node(other.node), children(){
    int size=other.children.size();
    for(int i=0;i<size; i++){
        children.push_back(other.children.at(i)->clone());
    }
}

//void Tree::clearChildren() {
//    for(int i=0;i>children.size(); i++) {
//        delete children.at(i);
//    }
//
//}

Tree * Tree::createTree(const Session &session, int rootLabel) {
    Tree* tree=session
}


void Tree::addChild(const Tree &child) {
    Tree* newChild=child.clone();
    children.push_back(newChild);
}

void Tree::addChild(Tree *child) {
    return addChild(*child);
}

//Assignment Operator Tree
Tree& Tree::operator=(const Tree &other) {
    if(&other!=this){
        node=other.node;
        for(int i=0;i<children.size(); i++) {
            delete children.at(i);
        }
        for(int i=0;i<other.children.size();i++){
            children.push_back(other.children.at(i)->clone());
        }
    }
    return *this;
}







CycleTree::CycleTree(int rootLabel, int currCycle): Tree(rootLabel), currCycle(currCycle){}

//Copy Constructor CycleTree
CycleTree::CycleTree(const CycleTree &other):Tree(other),currCycle(other.currCycle) {}

//Assignment Operator CycleTree
CycleTree & CycleTree::operator=(const CycleTree &other) {
    if(&other!= this){
        Tree::operator=(other);
        currCycle=other.currCycle;
    }
    return *this;
}

CycleTree* CycleTree::clone() const{return new CycleTree(*this);}



MaxRankTree::MaxRankTree(int rootLabel):Tree(rootLabel) {}

//Copy Constructor MaxRankTree
MaxRankTree::MaxRankTree(const MaxRankTree &other):Tree(other) {}
MaxRankTree* MaxRankTree::clone() const {return new MaxRankTree(*this);}


//Assignment Operator MaxRankTree
MaxRankTree & MaxRankTree::operator=(const MaxRankTree &other) {
    if(&other!= this){
        Tree::operator=(other);
    }
    return *this;
}

RootTree::RootTree(int rootLabel):Tree(rootLabel) {}

//Copy Constructor RootTree
RootTree::RootTree(const RootTree &other):Tree(other) {}

//RootTree* RootTree::clone() const {return new RootTree(*this);}

//Assignment Operator RootTree
RootTree & RootTree::operator=(const RootTree &other) {
    if(&other!= this){
        Tree::operator=(other);
    }
    return *this;
}

RootTree * RootTree::clone() const {return new RootTree(*this);}

int RootTree::traceTree() {
    return node;
}





