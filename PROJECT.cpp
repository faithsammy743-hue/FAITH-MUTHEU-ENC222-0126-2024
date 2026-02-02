#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* ===== Base Class ===== */
class SpatialFeature {
protected:
    int id;
    string type;

public:
    SpatialFeature(int i, string t) {
        id = i;
        type = t;
    }

    int getID() {
        return id;
    }

    string getType() {
        return type;
    }

    virtual void display() = 0;
    virtual bool insideBox(double xmin, double ymin, double xmax, double ymax) = 0;
};

/* ===== Derived Class ===== */
class GeometryFeature : public SpatialFeature {
private:
    vector<double> x; // coordinates
    vector<double> y;

public:
    GeometryFeature(int i, string t, vector<double> xv, vector<double> yv)
        : SpatialFeature(i, t) {
        x = xv;
        y = yv;
    }

    void display() {
        cout << type << " ID " << id << ": ";
        for (size_t i = 0; i < x.size(); i++) {
            cout << "(" << x[i] << "," << y[i] << ") ";
        }
        cout << endl;
    }

    bool insideBox(double xmin, double ymin, double xmax, double ymax) {
        for (size_t i = 0; i < x.size(); i++) {
            if (x[i] >= xmin && x[i] <= xmax && y[i] >= ymin && y[i] <= ymax)
                return true;
        }
        return false;
    }
};

/* ===== Data Manager ===== */
class SpatialDataManager {
private:
    vector<GeometryFeature> features;

public:
    void addFeature(const GeometryFeature &feature) {
        features.push_back(feature);
    }

    void displayAll() {
        cout << "All Features:\n";
        for (size_t i = 0; i < features.size(); i++) {
            features[i].display();
        }
    }

    void searchByID(int id) {
        for (size_t i = 0; i < features.size(); i++) {
            if (features[i].getID() == id) {
                cout << "Feature Found:\n";
                features[i].display();
                return;
            }
        }
        cout << "Feature not found.\n";
    }

    void boundingBoxQuery(double xmin, double ymin, double xmax, double ymax) {
        cout << "Features inside bounding box:\n";
        for (size_t i = 0; i < features.size(); i++) {
            if (features[i].insideBox(xmin, ymin, xmax, ymax))
                features[i].display();
        }
    }
};

/* ===== MAIN FUNCTION ===== */
int main() {
    SpatialDataManager manager;

    // Add Point
    manager.addFeature(GeometryFeature(1, "Point", {10}, {15}));
    manager.addFeature(GeometryFeature(2, "Point", {25}, {30}));

    // Add Line (3 points)
    manager.addFeature(GeometryFeature(3, "Line", {5, 15, 25}, {5, 15, 5}));

    // Add Polygon (4 points)
    manager.addFeature(GeometryFeature(4, "Polygon", {10, 20, 20, 10}, {10, 10, 20, 20}));

    // Display all features
    manager.displayAll();

    // Search by ID
    cout << "\nSearch Feature ID = 3:\n";
    manager.searchByID(3);

    // Bounding Box Query
    cout << "\nBounding Box Query (0,0)-(18,18):\n";
    manager.boundingBoxQuery(0, 0, 18, 18);

    return 0;
}
