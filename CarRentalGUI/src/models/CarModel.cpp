#include "CarModel.h"

void CarController::countCars(int id)
{
    auto carCount = storage.select(count(id));
}