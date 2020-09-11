#ifndef SUFFIX_TREE
#define SUFFIX_TREE

#include <string>
#include <vector>

class SuffixTreeBuilder;

class SuffixTreeVertex;

class SuffixTree {
public:
	SuffixTree(const std::string &);
	
	~SuffixTree();

	int getEntryIndex(std::string);
private:
	SuffixTreeBuilder * builder;
};

class SuffixTreeBuilder {
public:
	void build(const std::string &);
	SuffixTreeVertex * getRoot();
	std::string getVertexSubstring();
};


class SuffixTreeVertex {
public:
	SuffixTreeVertex(int, int);

	~SuffixTreeVertex();

	void updateInfo(int, int);

	std::pair<int, int> getInfo();

	std::vector<SuffixTreeVertex *> * getChildren();

	void addChildRelation(SuffixTreeVertex *);

	void removeChildRelation(SuffixTreeVertex *);
	
	SuffixTreeVertex * getParent();

	bool isRoot();

	bool isLeaf();

private:
	std::vector<SuffixTreeVertex *> * children;
	SuffixTreeVertex * parent;
	int suffixTreeStringEntryIndex, suffixTreeStringSubstringLength;
};

#endif