#include "utils.h"

void create_directory (const char *path)
{
    if (mkdir(path,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != -1)
        printf("[INFO] Output directory created at:> %s\n",path);
    else
        fprintf(stderr,"[INFO] Output directory already exists!\n");

    std::string filename = path;
    filename += "/pathways";
    if (mkdir(filename.c_str(),S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != -1)
        printf("[INFO] Pathways output directory created at:> %s\n",filename.c_str());
    else
        fprintf(stderr,"[INFO] Pathways output directory already exists!\n");
}

void write_vector_to_file (std::vector<double> arr, std::string filename)
{
    FILE *file = fopen(filename.c_str(),"w+");
    for (uint32_t i = 0; i < arr.size(); i++) fprintf(file,"%g\n",arr[i]);
    fclose(file);
}

void write_geometric_info_to_file (std::string filename,\
                    std::vector<double> segments,const double mean_segment_length, const double std_segment_length,\
                    std::vector<double> angles,const double mean_biff_angle, const double std_biff_angle)
{
    FILE *file = fopen(filename.c_str(),"w+");
    fprintf(file,"[INFO] Total number of segment = %lu\n",segments.size());
    fprintf(file,"[INFO] Segment length = %g +/- %g mm\n",mean_segment_length,std_segment_length);
    fprintf(file,"[INFO] Total number of bifurcations = %lu\n",angles.size());
    fprintf(file,"[INFO] Bifurcation angle = %g +/- %g degrees\n",mean_biff_angle,std_biff_angle);
    fprintf(file,"%.2lf +/- %.2lf\t%.2lf +/- %.2lf\t%lu\t%lu\n",mean_segment_length,std_segment_length,mean_biff_angle,std_biff_angle,segments.size(),angles.size());
    fclose(file);
}

void write_electric_info_to_file (std::string filename,\
                    const double max_lat_error, const double min_ref_lat, const double max_ref_lat,\
                    const double min_aprox_lat, const double max_aprox_lat,\
                    const double rmse, const double rrmse,\
                    const double epsilon_2ms, const double epsilon_5ms)
{
    FILE *file = fopen(filename.c_str(),"a");
    fprintf(file,"[INFO] Reference --> || min.LAT = %.2lf ms || max.LAT = %.2lf ms ||\n",min_ref_lat,max_ref_lat);
    fprintf(file,"[INFO] Aproximation --> || min.LAT = %.2lf ms || max.LAT = %.2lf ms || max.ERROR = %.2lf ms\n",min_aprox_lat,max_aprox_lat,max_lat_error);
    fprintf(file,"[INFO] || RMSE = %.2lf ms || RRMSE = %.2lf %% ||\n",rmse,rrmse);
    fprintf(file,"[INFO] || Epsilon 2ms = %.2lf %% || Epsilon 5ms = %.2lf ||\n",epsilon_2ms,epsilon_5ms);
    fprintf(file,"%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\n",min_aprox_lat,max_aprox_lat,max_lat_error,rmse,rrmse,epsilon_2ms,epsilon_5ms);
    fclose(file);
}

void calc_mean_std (std::vector<double> arr, double &mean, double &std)
{
    double sum = 0.0;
    double n = (double)arr.size();

    for (uint32_t i = 0; i < arr.size(); i++) sum += arr[i];
    mean = sum / n;

    sum = 0.0;
    for (uint32_t i = 0; i < arr.size(); i++) sum += pow(arr[i]-mean,2);
    std = sqrt(sum / n);
}

double euclidean_norm (const double x1, const double y1, const double z1,\
                    const double x2, const double y2, const double z2)
{
    return sqrt( pow(x2-x1,2) + pow(y2-y1,2) + pow(z2-z1,2) );
}

double calc_angle_between_vectors (const double u[], const double v[])
{
    double dot_product = u[0]*v[0] + u[1]*v[1] + u[2]*v[2];

    double angle_radians = acos(dot_product);
    if (std::isnan(angle_radians)) angle_radians = 0.0;

    // Return the angle in degrees
    return angle_radians * 180.0 / M_PI;
}

bool check_collinear (const double x1, const double y1, const double z1,\
                          const double x2, const double y2, const double z2,\
                          const double x3, const double y3, const double z3,\
                          const double x4, const double y4, const double z4)
{
    if (x1 == x3 && y1 == y3 && z1 == z3 &&\
        x2 == x4 && y2 == y4 && z2 == z4)
        return true;
    else
        return false;
}

bool check_user_input (int argc, char *argv[])
{
    int num_networks = argc-1;
    // Check if all the input arguments are INI configuration files
    for (int i = 0; i < argc-2; i++)
    {
        std::string config_filename = argv[i+1];
        printf("%s\n",config_filename.c_str());
        if (!check_extension(config_filename,"ini")) return false;
    }
    // Check if the last argument is a directory
    return (check_folder(argv[argc-1])) ? true : false;
}

bool check_extension (std::string filename, std::string target_extension)
{
    size_t nlen = filename.size();
    std::string extension = filename.substr( nlen-3, nlen );
    return (extension == target_extension) ? true : false;
}

bool check_folder (std::string filename)
{
    size_t nlen = filename.size();
    size_t npos = filename.find_first_of(".");
    return (npos != nlen-4) ? true : false;
}

void usage (const char pname[])
{
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Usage:> %s <input_config>\n",pname);
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Example:> %s inputs/benchmark_2d.ini\n",pname);
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");        
}

void usage_multiple_network (const char pname[])
{
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Usage:> %s [list_of_input_config] <output_dir>\n",pname);
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Example:> %s inputs/benchmark_3d_cuboid_north.ini inputs/benchmark_3d_cuboid_east.ini inputs/benchmark_3d_cuboid_west.ini outputs/benchmark3d:cuboid\n",pname);
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}