#include "graphedge.h"
#include "graphnode.h"
#include "memory"


GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    // rREMOVE
    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(edge);
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
     _chatBot = std::move(chatbot);

    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    // REMOVDE
    //_chatBot = nullptr;
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // return _childEdges[index];
    // auto child _childEdges[index]
    return (_childEdges[index]).get();
    ////
    //// EOF STUDENT CODE
}