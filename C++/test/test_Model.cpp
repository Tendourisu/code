#include <cassert>
#include "Model.hpp"

int main() {
    // Create a model with some lines
    Model<3> model;
    double coordinates1[3] = {0, 0, 0};
    double coordinates2[3] = {1, 1, 1};
    model.AddLine(Point<3>(coordinates1), Point<3>(coordinates2));
    double coordinates3[3] = {1, 1, 1};
    double coordinates4[3] = {2, 2, 2};
    model.AddLine(Point<3>(coordinates3), Point<3>(coordinates4));
    double coordinates5[3] = {2, 2, 2};
    double coordinates6[3] = {3, 3, 3};
    model.AddLine(Point<3>(coordinates5), Point<3>(coordinates6));

    // Test removing a line at index 1
    assert(model.RemoveLine(1));
    assert(model.Lines.size() == 2);
    assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(0) == 0);
    assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(1) == 0);
    assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(2) == 0);
    assert(model.Lines[0]->GetPointsVector()[1]->GetCoordinate(0) == 1);
    assert(model.Lines[0]->GetPointsVector()[1]->GetCoordinate(1) == 1);
    assert(model.Lines[0]->GetPointsVector()[1]->GetCoordinate(2) == 1);
    assert(model.Lines[1]->GetPointsVector()[0]->GetCoordinate(0) == 2);
    assert(model.Lines[1]->GetPointsVector()[0]->GetCoordinate(1) == 2);
    assert(model.Lines[1]->GetPointsVector()[0]->GetCoordinate(2) == 2);
    assert(model.Lines[1]->GetPointsVector()[1]->GetCoordinate(0) == 3);
    assert(model.Lines[1]->GetPointsVector()[1]->GetCoordinate(1) == 3);
    assert(model.Lines[1]->GetPointsVector()[1]->GetCoordinate(2) == 3);

    // Test removing a line at index 0
    assert(model.RemoveLine(0));
    assert(model.Lines.size() == 1);
    assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(0) == 2);
    assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(1) == 2);
    assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(2) == 2);
    assert(model.Lines[0]->GetPointsVector()[1]->GetCoordinate(0) == 3);
    assert(model.Lines[0]->GetPointsVector()[1]->GetCoordinate(1) == 3);
    assert(model.Lines[0]->GetPointsVector()[1]->GetCoordinate(2) == 3);

    // Test removing a line at index 0 when there is only one line left
    assert(model.RemoveLine(0));
    assert(model.Lines.size() == 0);

    // Test removing a line at index 0 when there are no lines
    assert(!model.RemoveLine(0));

    // Test removing a line at index 0 when there are no lines
    assert(!model.RemoveLine(0));

    // Test removing a line at index 0 when there are no lines
    assert(!model.RemoveLine(0));

    
    // Test adding a line
    double coordinates7[3] = {4, 4, 4};
    double coordinates8[3] = {5, 5, 5};
model.AddLine(Point<3>(coordinates7), Point<3>(coordinates8));
assert(model.Lines.size() == 1);
assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(0) == 4);
assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(1) == 4);
assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(2) == 4);
assert(model.Lines[0]->GetPointsVector()[1]->GetCoordinate(0) == 5);
assert(model.Lines[0]->GetPointsVector()[1]->GetCoordinate(1) == 5);
assert(model.Lines[0]->GetPointsVector()[1]->GetCoordinate(2) == 5);

// Test adding a face
    double coordinates9[3] = {6, 6, 6};
    double coordinates10[3] = {7, 7, 7};
    double coordinates11[3] = {8, 8, 8};
model.AddFace(Point<3>(coordinates9), Point<3>(coordinates10), Point<3>(coordinates11));
assert(model.Faces.size() == 1);
assert(model.Faces[0]->GetPointsVector()[0]->GetCoordinate(0) == 6);
assert(model.Faces[0]->GetPointsVector()[0]->GetCoordinate(1) == 6);
assert(model.Faces[0]->GetPointsVector()[0]->GetCoordinate(2) == 6);
assert(model.Faces[0]->GetPointsVector()[1]->GetCoordinate(0) == 7);
assert(model.Faces[0]->GetPointsVector()[1]->GetCoordinate(1) == 7);
assert(model.Faces[0]->GetPointsVector()[1]->GetCoordinate(2) == 7);
assert(model.Faces[0]->GetPointsVector()[2]->GetCoordinate(0) == 8);
assert(model.Faces[0]->GetPointsVector()[2]->GetCoordinate(1) == 8);
assert(model.Faces[0]->GetPointsVector()[2]->GetCoordinate(2) == 8);

// Test modifying a line
    double coordinates12[3] = {9, 9, 9};
model.ModifyLine(0, 0, Point<3>(coordinates12));
assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(0) == 9);
assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(1) == 9);
assert(model.Lines[0]->GetPointsVector()[0]->GetCoordinate(2) == 9);

// Test modifying a face
    double coordinates13[3] = {10, 10, 10};
model.ModifyFace(0, 1, Point<3>(coordinates13));
assert(model.Faces[0]->GetPointsVector()[1]->GetCoordinate(0) == 10);
assert(model.Faces[0]->GetPointsVector()[1]->GetCoordinate(1) == 10);
assert(model.Faces[0]->GetPointsVector()[1]->GetCoordinate(2) == 10);

// Test removing a face
assert(model.RemoveFace(0));
assert(model.Faces.size() == 0);

// Test clearing the model
model.Clear();
assert(model.Lines.size() == 0);
assert(model.Faces.size() == 0);
}