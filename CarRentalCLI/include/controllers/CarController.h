#pragma once
#include <string>
#include <vector>
#include <optional>

#include "models/CarModel.h"

/**
 * @brief Modifies and reads the Car table
 */
class CarController
{
public:
    /**
     * @param regNo registration number of car
     * @param brand brand name of car
     * @param model model name of car
     * @return true if succeeded
     */
    bool AddCar(
        const std::string &regNo, const std::string &brand,
        const std::string &model);

    /**
     * @param id id of car to edit
     * @param regNo new registration number
     * @param brand new brand name
     * @param model new model name
     * @return true if succeeded
     */
    bool EditCar(
        int id, const std::string &regNo, const std::string &brand,
        const std::string &model);

    /**
     * @param id id of car to remove
     * @return true if succeeded
     */
    bool RemoveCar(int id);

    /**
     * @return count of cars in system
     */
    int CountCars();

    /**
     *
     * @param carID id of car to fetch
     * @return CarModel instance of car
     */
    std::optional<CarModel> GetCarById(int carID);

    /**
     *
     * @param searchPhrase phrase to search
     * @param field what field of CarModel to search
     * Optional:
     * @param startDate  start of rent period
     * @param endDate  end of rent period
     * @return
     */
    std::vector<CarModel> SearchCar(
        const std::string &searchPhrase, int field,
        const std::string &startDate = "",
        const std::string &endDate   = "");
};
