package com.algorithms.evolutionary.tsp;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by mahidhar on 4/29/17.
 */
public class Route {
    private List<City> route;
    private double distance = 0;

    public Route(Individual individual, List<City> cities) {
        // Get individual's chromosome
        route = individual.getChromosome().stream().map(gene -> cities.get(gene)).collect(Collectors.toList());
    }

    public double getDistance() {
        if (distance > 0) {
            return distance;
        }

        double totalDistance = route.stream().map(city -> city.distanceFrom(route.get(0))).reduce(0.0, (sum, n) -> sum + n);
        distance = totalDistance + route.get(route.size()-1).distanceFrom(route.get(0));
        return distance;
    }
}
