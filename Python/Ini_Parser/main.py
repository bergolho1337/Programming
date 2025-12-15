import sys
import numpy as np
import configparser

class InputParams:
    # Input variables
    num_population = 512
    result_dir = ""
    clinical_qrs_filename = ""
    electrodes_filename = ""

    # Methods
    def __init__ (self):
        print("Creating 'ConfigParser' object ...")
    
    def read_params_from_ini (self, config, filename):
        print("Reading INI config file '%s'" % (filename))
        # Read [main] section
        self.num_population = int(config["main"]["num_population"])
        # Read [save_result] section
        self.clinical_qrs_filename = config["save_result"]["clinical_qrs_filename"]
        self.result_dir = config["save_result"]["result_dir"]
        self.electrodes_filename = config["save_result"]["electrodes_filename"]

    def print (self):
        print("num_population = '%s'" % (self.num_population))
        print("clinical_qrs_filename = '%s'" % (self.clinical_qrs_filename))
        print("result_dir = '%s'" % (self.result_dir))
        print("electrodes_filename = '%s'" % (self.electrodes_filename))


def main():
    if len(sys.argv) != 2:
        print("-------------------------------------------------------------------------")
        print("Usage:> python %s <input_file>" % sys.argv[0])
        print("-------------------------------------------------------------------------")
        print("<input_file> = Input file with the INI configuration")
        print("-------------------------------------------------------------------------")
        return 1

    input_file = sys.argv[1]
    config = configparser.ConfigParser()
    filename = config.read(input_file)[0]
    params = InputParams()
    params.read_params_from_ini(config, filename)
    params.print()

if __name__ == "__main__":
	main()
