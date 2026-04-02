#ifndef INCIDENTFUNCTIONS_H
#define INCIDENTFUNCTIONS_H

#include <vector>
#include "Incident.h"

void createIncident(std::vector<Incident>& incidents);
void appendTicket(std::vector<Incident>& incidents);
void removeIncident(std::vector<Incident>& incidents);
void sortIncident(std::vector<Incident>& incidents);
void searchIncident(std::vector<Incident>& incidents);
void priorityIncident(std::vector<Incident>& incidents);
void reverseIncident(std::vector<Incident>& incidents);
void displayAllIncidents(const std::vector<Incident>& incidents);
void updateIncident(std::vector<Incident>& incidents);
void filterIncident(const std::vector<Incident>& incidents);

#endif

