#ifndef TREE_H_
#define TREE_H_

#include <vector>
//#include "Graph.h"
#include "stack"

class Session;

class Tree{
public:
    Tree(int rootLabel);
    Tree(const Tree& other);
    void addChild(const Tree& child);
    void addChild(Tree* child);
    virtual Tree* clone() const =0 ;
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    Tree& operator=(const Tree& other);
    virtual ~Tree();

protected:
    int node;
    std::vector<Tree*> children;
    int depth;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    CycleTree(const CycleTree& other);
    CycleTree& operator=(const CycleTree& other);
    virtual ~CycleTree();

    virtual int traceTree();
    virtual CycleTree* clone() const;
    void addChild(const CycleTree& child);
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    virtual MaxRankTree* clone() const;
    MaxRankTree(int rootLabel);
    MaxRankTree(const MaxRankTree& other);
    MaxRankTree& operator=(const MaxRankTree& other);
    virtual int traceTree();
    virtual ~MaxRankTree();
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    RootTree(const RootTree& other);
    RootTree& operator=(const RootTree& other);
    virtual int traceTree();
    virtual RootTree* clone() const;
    virtual ~RootTree();

}
;
#endif
