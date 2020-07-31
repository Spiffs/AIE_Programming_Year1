#pragma once

class Graph2D;

class Graph2DEditor
{
public:
	Graph2DEditor();
	virtual ~Graph2DEditor();

	void Update(float deltaTime);
	void Draw();

	Graph2D* GetGraph();
	void SetGraph(Graph2D* graph);


private:

	Graph2D* m_graph;

};

