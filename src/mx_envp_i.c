#include "ush.h"

static t_envp *envp_getpath(t_envp *res) {
    char buf[] =
    "PLA/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:PLA";
    char *home = mx_strjoin(getenv("HOME"), "/.brew/bin");
    char *buf2 = mx_replace_substr(buf, "PLA", home);
    char *buf3 = mx_strjoin("PATH=", buf2);

    setenv("PATH", buf2, 1);
    mx_envp_replace(&res, buf3);
    mx_strdel(&home);
    mx_strdel(&buf2);
    mx_strdel(&buf3);
    return res;
}

static t_envp *envp_gethomelvl(int flag, t_envp *res) {
    if (flag == 1) {
        struct passwd *pw = getpwuid(getuid());
        char *home = mx_strjoin("HOME=", strdup(pw->pw_dir));
        mx_envp_add(&res, home);
        setenv("HOME", pw->pw_dir, 1);
        mx_strdel(&home);
    }
    if (flag == 2) {
        setenv("SHLVL", "1", 1);
        mx_envp_add(&res, "SHLVL=1");
    }
    if (flag == 3) {
        setenv("_", "env", 1);
        mx_envp_add(&res, "_=env");
    }
    if (flag == 4) {
        struct passwd *pw = getpwuid(getuid());
        setenv("LOGNAME", pw->pw_name, 1);
    }
    return res;
}

static t_envp *envp_getpwd(int flag, t_envp *res) {
    char *buf = mx_strnew(1024);
    char *buf2 = NULL;
    char *buf3 = NULL;

    if (flag == 1) {
        getcwd(buf, 1024);
        buf2 = mx_strjoin("PWD=", buf);
        buf3 = mx_strjoin("OLDPWD=", buf);
        setenv("PWD", buf, 1);
        setenv("OLDPWD", buf, 1);
        mx_envp_add(&res, buf2);
        mx_envp_add(&res, buf3);
        mx_strdel(&buf3);
    }
    mx_strdel(&buf);
    mx_strdel(&buf2);
    return res;
}

t_envp *mx_envp_i_fill(void) {
    t_envp *res = NULL;

    // if (!(getenv("PWD")))
        res = envp_getpwd(1, res);
    if (!(getenv("HOME")))
        res = envp_gethomelvl(1, res);
    if (!(getenv("SHLVL")))
        res = envp_gethomelvl(2, res);
    else
        mx_envp_shlvl(res);
    if (!(getenv("_")))
        res = envp_gethomelvl(3, res);
    if (!(getenv("PATH")))
        res = envp_getpath(res);
    if (!getenv("LOGNAME"))
        res = envp_gethomelvl(4, res);
    return res;
}
