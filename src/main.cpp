//
// Copyright 2015 David Vadovszki
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <iostream>
#include <string>

#include <boost/program_options.hpp>


int main(int argc, char** argv)
{
    const auto SUCCESS = 0;
    const auto ERROR_UNHANDLED_EXCEPTION = 1;
    const auto ERROR_USAGE = 2;

    try {
        // define and parse the program options
        namespace po = boost::program_options;
        po::options_description desc("Options");
        desc.add_options()
            ("help,h", "Print help messages")
            ("verbose,v", "verbose output, can be specified multiple times");

        po::positional_options_description pos_args;
        po::variables_map vm;

        try {
            po::store(po::command_line_parser(argc, argv).options(desc)
                    .positional(pos_args).run(), vm);

            // display help if requested, do this before notify might throw
            if (vm.count("help")) {
                std::cout << "Usage: " << argv[0] << " [options]\n"
                    << desc << std::endl;
                return SUCCESS;
            }

            // throws on error
            po::notify(vm);
        }
        catch (po::error& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
            std::cerr << "Usage: " << argv[0] << " [options]\n"
                << desc << std::endl;
            return ERROR_USAGE;
        }

        if (vm.count("verbose")) {
            std::cout << "Verbose output enabled..." << std::endl;
        }

        // TODO, kick off OGRE

    }
    catch (std::exception& e) {
        std::cerr << "Unhandled Exception reached main: " << e.what()
            << std::endl;
        return ERROR_UNHANDLED_EXCEPTION;
    }

    return SUCCESS;
}
