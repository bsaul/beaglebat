/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

int main(int argc, char **argv)
{
    config_t cfg, *cf;
    config_setting_t *hardware_config;
    long long int rate;
    int enabled;

    cf = &cfg;
    config_init(cf);

    if (!config_read_file(cf, "beaglebat.cfg")) {
        fprintf(stderr, "%s:%d - %s\n",
            config_error_file(cf),
            config_error_line(cf),
            config_error_text(cf));
        config_destroy(cf);
        return(EXIT_FAILURE);
    }

    if (config_lookup_bool(cf, "enabled", &enabled))
        printf("Enabled: %s\n", enabled ? "Yep" : "Nope");
    else 
        printf("Enabled is not defined\n");

/*
    hardware_config = config_lookup(&cfg, "hardware");

    if(hardware_config != NULL)
    {
    	printf("this worked!");
    	if(config_setting_lookup_int64(hardware_config, "rate", &rate))
    		        printf("Sampling rate: %s\n", rate);
    	else
    		printf("Sampling rate not defined");
    } else {
    	printf("Well I tried");
    }
*/

    if (config_lookup_int64(cf, "hardware.rate", &rate))
        printf("Sampling rate: %lli\n", rate);
    else
    	printf("Sampling rate not defined");

    config_destroy(cf);
    return 0;
}