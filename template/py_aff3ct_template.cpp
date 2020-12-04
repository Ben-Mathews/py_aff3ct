#include "py_aff3ct.hpp"

using namespace aff3ct;

PYBIND11_MODULE(py_aff3ct, m){
	// Split in two following https://pybind11.readthedocs.io/en/stable/advanced/misc.html#avoiding-c-types-in-docstrings
	// for enhancing python doc
	setControlMode(rang::control::Force);
	std::vector<wrapper::Wrapper_py*> wrappers;
	py::module_ m0 = m.def_submodule("tools");
	std::unique_ptr<wrapper::Wrapper_py> wrapper_gngi       (new wrapper::Wrapper_Gaussian_noise_generator_implem(m0));
	wrappers.push_back(wrapper_gngi.get());

	py::module_ m_sequence = m0.def_submodule("sequence");
	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_sequence(new aff3ct::wrapper::Wrapper_Sequence(m_sequence));
	wrappers.push_back(wrapper_sequence.get());

	py::module_ mod_frozenbits_generator = m0.def_submodule("frozenbits_generator");
	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_frozenbits_generator(new aff3ct::wrapper::Wrapper_Frozenbits_generator(mod_frozenbits_generator));
	wrappers.push_back(wrapper_frozenbits_generator.get());

	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_frozenbits_generator_bec(new aff3ct::wrapper::Wrapper_Frozenbits_generator_BEC(mod_frozenbits_generator));
	wrappers.push_back(wrapper_frozenbits_generator_bec.get());

	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_frozenbits_generator_ga(new aff3ct::wrapper::Wrapper_Frozenbits_generator_GA(mod_frozenbits_generator));
	wrappers.push_back(wrapper_frozenbits_generator_ga.get());

	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_frozenbits_generator_ga_arikan(new aff3ct::wrapper::Wrapper_Frozenbits_generator_GA_Arikan(mod_frozenbits_generator));
	wrappers.push_back(wrapper_frozenbits_generator_ga_arikan.get());

	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_frozenbits_generator_file(new aff3ct::wrapper::Wrapper_Frozenbits_generator_file(mod_frozenbits_generator));
	wrappers.push_back(wrapper_frozenbits_generator_file.get());

	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_frozenbits_generator_5g(new aff3ct::wrapper::Wrapper_Frozenbits_generator_5G(mod_frozenbits_generator));
	wrappers.push_back(wrapper_frozenbits_generator_5g.get());

	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_frozenbits_generator_tv(new aff3ct::wrapper::Wrapper_Frozenbits_generator_TV(mod_frozenbits_generator));
	wrappers.push_back(wrapper_frozenbits_generator_tv.get());
{other_tool_wrappers}

	py::module_ m1 = m.def_submodule("module");

	std::unique_ptr<wrapper::Wrapper_py> wrapper_socket       (new wrapper::Wrapper_Socket         (m1));
	wrappers.push_back(wrapper_socket.get());

	std::unique_ptr<wrapper::Wrapper_py> wrapper_task         (new wrapper::Wrapper_Task           (m1));
	wrappers.push_back(wrapper_task.get());

	std::unique_ptr<wrapper::Wrapper_py> wrapper_module       (new wrapper::Wrapper_Module         (m1));
	wrappers.push_back(wrapper_module.get());

	py::module_ m2 = m1.def_submodule("py_module");
	std::unique_ptr<wrapper::Wrapper_py> wrapper_py_module    (new wrapper::Wrapper_Py_Module      (m2));
	wrappers.push_back(wrapper_py_module.get());

	py::module_ mod_monitor = m1.def_submodule("monitor");
	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_monitor(new aff3ct::wrapper::Wrapper_Monitor(mod_monitor));
	wrappers.push_back(wrapper_monitor.get());
	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_monitor_bfer_ar(new aff3ct::wrapper::Wrapper_Monitor_BFER_AR<>(mod_monitor));
	wrappers.push_back(wrapper_monitor_bfer_ar.get());
	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_monitor_bfer(new aff3ct::wrapper::Wrapper_Monitor_BFER<>(mod_monitor));
	wrappers.push_back(wrapper_monitor_bfer.get());
	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_monitor_exit(new aff3ct::wrapper::Wrapper_Monitor_EXIT<>(mod_monitor));
	wrappers.push_back(wrapper_monitor_exit.get());
	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_monitor_mi(new aff3ct::wrapper::Wrapper_Monitor_MI<>(mod_monitor));
	wrappers.push_back(wrapper_monitor_mi.get());
	std::unique_ptr<aff3ct::wrapper::Wrapper_py> wrapper_monitor_bfer_reduction(new aff3ct::wrapper::Wrapper_Monitor_reduction_BFER(mod_monitor));
	wrappers.push_back(wrapper_monitor_bfer_reduction.get());

{other_module_wrappers}

	for (size_t i = 0; i < wrappers.size(); i++)
		wrappers[i]->definitions();
}