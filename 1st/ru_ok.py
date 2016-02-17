#!/usr/bin/python
# -*- coding: UTF-8 -*-

import urllib

pageUrl = 'http://fra.dev.cic.nsn-rdnet.net/trunk/grid'

global_html = '''
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<!-- saved from url=(0043)http://fra.dev.cic.nsn-rdnet.net/trunk/grid -->
<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en"><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
 <title>BuildBot: NG</title>
 <link href="./BuildBot_files/buildbot.css" rel="stylesheet" type="text/css">
<style type="text/css"></style><style id="style-1-cropbar-clipper">/* Copyright 2014 Evernote Corporation. All rights reserved. */
.en-markup-crop-options {
    top: 18px !important;
    left: 50% !important;
    margin-left: -100px !important;
    width: 200px !important;
    border: 2px rgba(255,255,255,.38) solid !important;
    border-radius: 4px !important;
}

.en-markup-crop-options div div:first-of-type {
    margin-left: 0px !important;
}
</style></head>

<body vlink="#800080">
<table class="Grid" border="0" cellspacing="0">
<tbody><tr>
<td class="title"><a href="http://viini.dev.salab.noklab.net/twiki/bin/view/SA/WebHome">NG</a></td>
<td valign="bottom" class="sourcestamp">latest</td>
<td valign="bottom" class="sourcestamp">292335</td>
<td valign="bottom" class="sourcestamp">292332</td>
<td valign="bottom" class="sourcestamp">292328</td>
<td valign="bottom" class="sourcestamp">292326</td>
<td valign="bottom" class="sourcestamp">292317</td>
<td valign="bottom" class="sourcestamp">292299</td>
<td valign="bottom" class="sourcestamp">292295</td>
<td valign="bottom" class="sourcestamp">292294</td>
<td valign="bottom" class="sourcestamp">292292</td>
<td valign="bottom" class="sourcestamp">292290</td>
<td valign="bottom" class="sourcestamp">292287</td>
<td valign="bottom" class="sourcestamp">292273</td>
<td valign="bottom" class="sourcestamp">292255</td>
<td valign="bottom" class="sourcestamp">292271</td>
<td valign="bottom" class="sourcestamp">292263</td>
<td valign="bottom" class="sourcestamp">292257</td>
<td valign="bottom" class="sourcestamp">292253</td>
<td valign="bottom" class="sourcestamp">292246</td>
<td valign="bottom" class="sourcestamp">292245</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/AMCOM/">AMCOM</a><br>(waiting)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/AMCOM/builds/1142">failed</a><br>
shell_2</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/AMCOM_CCM/">AMCOM_CCM</a><br>(waiting)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/AMCOM_CCM/builds/1049">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT/">CATAPULT</a><br>(building)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT/builds/9077">building</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT/builds/9076">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT/builds/9075">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT/builds/9074">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT/builds/9073">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT_X800/">CATAPULT_X800</a><br>(building)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT_X800/builds/5392">building</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT_X800/builds/5391">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT_X800/builds/5390">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT_X800/builds/5389">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATAPULT_X800/builds/5388">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATA_ATHENS/">CATA_ATHENS</a><br>(building)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATA_ATHENS/builds/273">building</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATA_ATHENS/builds/272">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATA_ATHENS/builds/271">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATA_ATHENS/builds/270">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/CATA_ATHENS/builds/269">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="white" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/LDAP_TEST/">LDAP_TEST</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/LDAP_TEST/builds/814">failed</a><br>
shell</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/LDAP_TEST/builds/813">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/PROFILING/">PROFILING</a><br>(building with 3 pending)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/PROFILING/builds/4391">building</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/PROFILING/builds/4390">failed</a><br>
shell_2</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/PROFILING/builds/4389">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/PROFILING/builds/4388">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/PROFILING/builds/4387">OK</a></td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/">SANITY</a><br>(building)</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16613">building</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16612">building</a></td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16611">failed</a><br>
shell_2</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16610">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16609">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16608">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16607">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16606">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16605">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16604">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16603">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/SANITY/builds/16602">OK</a></td>
</tr>
<tr>
<td valign="center" bgcolor="white" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/TDL/">TDL</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST/">UNITTEST</a><br>(building with 5 pending)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST/builds/15253">building</a></td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST/builds/15252">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST/builds/15251">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST/builds/15250">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST/builds/15249">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST/builds/15248">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST/builds/15247">OK</a></td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST_gcc46/">UNITTEST_gcc46</a><br>(building)</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST_gcc46/builds/12245">building</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST_gcc46/builds/12244">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST_gcc46/builds/12243">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST_gcc46/builds/12242">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST_gcc46/builds/12241">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST_gcc46/builds/12240">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST_gcc46/builds/12239">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UNITTEST_gcc46/builds/12238">OK</a></td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UT_SINGLE_OK/">UT_SINGLE_OK</a><br>(building with 5 pending)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UT_SINGLE_OK/builds/9614">building</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UT_SINGLE_OK/builds/9613">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UT_SINGLE_OK/builds/9612">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UT_SINGLE_OK/builds/9611">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/UT_SINGLE_OK/builds/9610">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/VALGRIND/">VALGRIND</a><br>(building with 6 pending)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/VALGRIND/builds/5312">building</a></td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/VALGRIND/builds/5311">failed</a><br>
shell_2</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_DEPLOY/">cNG_DEPLOY</a><br>(waiting)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_DEPLOY/builds/132">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/">cNG_SANITY</a><br>(building)</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/861">building</a></td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/860">building</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/859">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/858">OK</a></td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/856">failed</a><br>
shell_4</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/855">failed</a><br>
shell_4</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/854">failed</a><br>
shell_4</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/853">failed</a><br>
shell_4</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/852">failed</a><br>
shell_4</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/851">failed</a><br>
shell_4</td>
<td class="build" bgcolor="red"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_SANITY/builds/850">failed</a><br>
shell_4</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_UNDEPLOY/">cNG_UNDEPLOY</a><br>(waiting)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_UNDEPLOY/builds/126">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
<tr>
<td valign="center" bgcolor="yellow" class="builder"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_UNITTEST/">cNG_UNITTEST</a><br>(building with 5 pending)</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="yellow"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_UNITTEST/builds/376">building</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_UNITTEST/builds/375">OK</a></td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_UNITTEST/builds/374">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build" bgcolor="#72ff75"><a href="http://fra.dev.cic.nsn-rdnet.net/trunk/builders/cNG_UNITTEST/builds/373">OK</a></td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
<td class="build">&nbsp;</td>
</tr>
</tbody></table>
<hr><div class="footer">
[<a href="http://fra.dev.cic.nsn-rdnet.net/trunk/index.html">welcome</a>]
<br>
<a href="http://buildbot.sourceforge.net/">Buildbot</a>-0.7.9 working for the <a href="http://viini.dev.salab.noklab.net/twiki/bin/view/SA/WebHome">NG</a> project.<br>
Page built: Thu 25 Jun 2015 09:55:23
</div>
'''


<div id="shanbay_extension_result" class="shanbay_extension_result"><div id="shanbay_extension_result_shanbaydict" class="shanbay_extension_result_engine"><div id="shanbay_extension_result_shanbaydict_caption" class="shanbay_extension_result_caption"></div><div id="shanbay_extension_result_shanbaydict_content" class="shanbay_extension_result_content"></div></div><div id="shanbay_extension_result_googletran" class="shanbay_extension_result_engine"><div id="shanbay_extension_result_googletran_caption" class="shanbay_extension_result_caption"></div><div id="shanbay_extension_result_googletran_content" class="shanbay_extension_result_content"></div></div><div id="shanbay_extension_result_wikizh" class="shanbay_extension_result_engine"><div id="shanbay_extension_result_wikizh_caption" class="shanbay_extension_result_caption"></div><div id="shanbay_extension_result_wikizh_content" class="shanbay_extension_result_content"></div></div><div id="shanbay_extension_result_wikien" class="shanbay_extension_result_engine"><div id="shanbay_extension_result_wikien_caption" class="shanbay_extension_result_caption"></div><div id="shanbay_extension_result_wikien_content" class="shanbay_extension_result_content"></div></div></div></body></html>

if __name__ == '__main__':
    # page = urllib.urlopen(pageUrl).read()
    # print 'page ='
    # print page
    