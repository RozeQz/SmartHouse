package com.SmartTech.Smarthouse.controllers;

import com.SmartTech.Smarthouse.dao.StationDAO;
import com.SmartTech.Smarthouse.models.StationData;
//import com.SmartTech.Smarthouse.repositories.StationDataRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;

@Controller
@RequestMapping("/stations")
public class StationsController {

    private final StationDAO stationDAO;
    @Autowired
    public StationsController(StationDAO stationDAO) {
        this.stationDAO = stationDAO;
    }

    @GetMapping ()
    public String index(Model model) {
        model.addAttribute("stations", stationDAO.allStations());
        return "stations/index";
    }

    @GetMapping("/{id}")
    public String show(@PathVariable("id") int id, Model model) {
        model.addAttribute("stations", stationDAO.stationById(id));
        return "stations/show";
    }

    @GetMapping("/new")
    public String newPerson(@ModelAttribute("station") StationData station) {
        return "stations/new";
    }

    @PostMapping()
    public String create(@ModelAttribute("station") @Valid StationData station,
                         BindingResult bindingResult) {
        if (bindingResult.hasErrors())
            return "stations/new";

        stationDAO.save(station);
        return "redirect:/stations";
    }

    @DeleteMapping("/{id}")
    public String delete(@PathVariable("id") int id) {
        stationDAO.delete(id);
        return "redirect:stations/";
    }

}