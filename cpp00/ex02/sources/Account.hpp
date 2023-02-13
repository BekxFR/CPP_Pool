// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account	t; //Account == t

	static int	getNbAccounts( void ); //Return Nbr accounts
	static int	getTotalAmount( void ); //Return Montant total
	static int	getNbDeposits( void ); //Return Nbr de depots
	static int	getNbWithdrawals( void ); //Return Nbr de retrait
	static void	displayAccountsInfos( void ); //Affichiche Infos des comptes

	Account( int initial_deposit ); // construct qui init le deposit
	~Account( void ); //destruct

	void	makeDeposit( int deposit ); //VOID qui fait un depot
	bool	makeWithdrawal( int withdrawal ); //Bool qui fait un retrait
	int		checkAmount( void ) const; //Int qui return le Amount 
	void	displayStatus( void ) const; //VOID qui affiche le status


private:

	static int	_nbAccounts; 
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void ); //Affiche l'heure

	int	_accountIndex;
	int	_amount;
	int	_nbDeposits;
	int	_nbWithdrawals;

	Account( void ); // Construct

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
