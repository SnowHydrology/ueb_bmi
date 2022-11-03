#ifndef BMI_UEB_H_INCLUDED
#define BMI_UEB_H_INCLUDED

#include <string>
#include <iostream>

#include "bmi.hxx"
#include "uebpgdecls.h"


class NotImplemented : public std::logic_error {
  public:
  NotImplemented() : std::logic_error("Not Implemented") { };
};


class BmiUeb : public bmi::Bmi {
  public:
    BmiUeb() {
      this->input_var_names[0]  = "Prec";    // Precipitation (m/h)
      this->input_var_names[1]  = "Ta";      // Air temperature (°C)
      this->input_var_names[2]  = "Tmin";    // Min air temperature (°C)
      this->input_var_names[3]  = "Tmax";    // Max air temperature (°C)
      this->input_var_names[4]  = "V";       // Wind speed (m/s)
      this->input_var_names[5]  = "RH";      // Relative humidity (-)
      this->input_var_names[6]  = "Vp";      // Vapor pressure (?)
      this->input_var_names[7]  = "AP";      // Air pressure (?)
      this->input_var_names[8]  = "Qsi";     // Incoming shortwave radiation (kJ/m2/hr)
      this->input_var_names[9]  = "Qli";     // Incoming longwave radiation (kJ/m2/hr)
      this->input_var_names[10] = "Qnet";    // Net radiation (kJ/m2/hr)
      this->input_var_names[11] = "Qg";      // Ground heat flux (kJ/m2/hr)
      this->input_var_names[12] = "Snowalb"; // Snow albedo (-)
      this->output_var_names[0] = "SWIT";    // Total outflow (rainfall + snowmelt) (m/h)
      this->output_var_names[1] = "Ws";      // Snow water equivalent (m)
    };

    void Initialize(std::string config_file);
    void Update();
    void UpdateUntil(double time);
    void Finalize();

    std::string GetComponentName();
    int GetInputItemCount();
    int GetOutputItemCount();
    std::vector<std::string> GetInputVarNames();
    std::vector<std::string> GetOutputVarNames();

    int GetVarGrid(std::string name);
    std::string GetVarType(std::string name);
    int GetVarItemsize(std::string name);
    std::string GetVarUnits(std::string name);
    int GetVarNbytes(std::string name);
    std::string GetVarLocation(std::string name);

    double GetCurrentTime();
    double GetStartTime();
    double GetEndTime();
    std::string GetTimeUnits();
    double GetTimeStep();

    void GetValue(std::string name, void *dest);
    void *GetValuePtr(std::string name);
    void GetValueAtIndices(std::string name, void *dest, int *inds, int count);

    void SetValue(std::string name, void *src);
    void SetValueAtIndices(std::string name, int *inds, int len, void *src);

    int GetGridRank(const int grid);
    int GetGridSize(const int grid);
    std::string GetGridType(const int grid);

    void GetGridShape(const int grid, int *shape);
    void GetGridSpacing(const int grid, double *spacing);
    void GetGridOrigin(const int grid, double *origin);

    void GetGridX(const int grid, double *x);
    void GetGridY(const int grid, double *y);
    void GetGridZ(const int grid, double *z);

    int GetGridNodeCount(const int grid);
    int GetGridEdgeCount(const int grid);
    int GetGridFaceCount(const int grid);

    void GetGridEdgeNodes(const int grid, int *edge_nodes);
    void GetGridFaceEdges(const int grid, int *face_edges);
    void GetGridFaceNodes(const int grid, int *face_nodes);
    void GetGridNodesPerFace(const int grid, int *nodes_per_face);

  private:
    ueb::Ueb _model;
    static const int input_var_name_count = 13;
    static const int output_var_name_count = 2;

    std::string input_var_names[13];
    std::string output_var_names[2];
};

#endif
