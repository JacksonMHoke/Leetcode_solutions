// 811. Subdomain Visit Count
/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
    num_visits={};
    for (let i=0; i<cpdomains.length; ++i) {
        let [rep, domain]=cpdomains[i].split(" ");
        rep=+rep;
        domain=domain.split(".");

        for (let j=domain.length-1; j>=0; --j) {
            if (j+1<domain.length)
                domain[j]+="."+domain[j+1];

            num_visits[domain[j]]=num_visits[domain[j]] ? num_visits[domain[j]]+rep : rep;
        }
    }

    rt = [];
    for (let subdomain in num_visits)
        rt.push(num_visits[subdomain]+" "+subdomain);
    return rt;
};