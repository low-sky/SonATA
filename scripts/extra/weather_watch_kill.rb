#!/usr/bin/env ruby
#
################################################################################
##
## File:    weather_watch_kill.rb
## Project: OpenSonATA
## Authors: Jon Richards, SETI Institute
##
## Copyright 2013 The SETI Institute
##
## OpenSonATA is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## OpenSonATA is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with OpenSonATA.  If not, see<http://www.gnu.org/licenses/>.
## 
## Implementers of this code are requested to include the caption
## "Licensed through SETI" with a link to setiQuest.org.
## 
## For alternate licensing arrangements, please contact
## The SETI Institute at www.seti.org or setiquest.org. 
##
#################################################################################

# Kill the weather watcher script

require 'rubygems'
require 'time'
require 'date'

require 'sys/proctable'
require 'time'

proc_name = "weather_watch.rb";

Sys::ProcTable.ps.each do |ps|
  if (ps.cmdline.downcase.index(proc_name.downcase) != nil)
	  puts "KILL pid=" + ps.pid.to_s;
	      Process.kill('KILL', ps.pid)
  end
end
