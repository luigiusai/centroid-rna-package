/*
 * $Id$
 *
 * CentroidFold: A generalized centroid estimator for predicting RNA
 *               secondary structures
 *
 * Copyright (C) 2008 Kengo Sato
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __INC_CENTROID_FOLD_H__
#define __INC_CENTROID_FOLD_H__

#include <string>
#include <list>
#include <vector>
#include <iosfwd>
#include "bp.h"

class CentroidFold
{
public:
  typedef SCFG::BP::Table<double> BPTable;

  enum {
    AUX,
    PFFOLD,
    CONTRAFOLD,
    ALIPFFOLD
  };
  
public:
  CentroidFold(unsigned int engine, bool run_as_mea=false,
	       unsigned int reserved_size=0);
  ~CentroidFold();

#if 0
  void execute(const std::string& seq, const std::vector<float>& gamma,
	       std::vector<std::string>& paren, std::vector<float>& ea,
	       const std::string& model="");
  void execute(const std::list<std::string>& seq, const std::vector<float>& gamma,
	       std::vector<std::string>& paren, std::vector<float>& ea,
	       const std::vector<std::string>& model);
  void execute(const std::vector<std::string>& seq, const std::vector<float>& gamma,
	       std::vector<std::string>& paren, std::vector<float>& ea,
	       const std::vector<std::string>& model);
  void execute(const std::list<std::string>& seq, const std::vector<float>& gamma,
	       std::vector<std::string>& paren, std::vector<float>& ea);
  void execute(const std::vector<std::string>& seq, const std::vector<float>& gamma,
	       std::vector<std::string>& paren, std::vector<float>& ea);
#endif

  void calculate_posterior(const std::string& seq, const std::string& model="");
  void calculate_posterior(const std::list<std::string>& seq,
			   const std::vector<std::string>& model);
  void calculate_posterior(const std::list<std::string>& seq);
  void calculate_posterior(const std::vector<std::string>& seq,
			   const std::vector<std::string>& model);
  void calculate_posterior(const std::vector<std::string>& seq);
  float decode_structure(float gamma, std::string& paren) const;
  std::pair<std::string,float> decode_structure(float gamma) const;
  void print(std::ostream& out, const std::string& name, const std::string& seq,
	     const std::vector<double>& gamma) const;
  void print_posterior(std::ostream& out, const std::string& seq, float th) const;
#ifdef HAVE_LIBRNA
  void ps_plot(const std::string& name, const std::string& seq, float g) const;
  void svg_plot(const std::string& name, const std::string& seq, float g) const;
#endif

private:
  unsigned int engine_;
  bool mea_;
  BPTable bp_;
};

#endif	// #ifndef __INC_CENTROID_FOLD_H__