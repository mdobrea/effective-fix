#ifndef FIXP_EXECUTIONREPORT_HPP_
#define FIXP_EXECUTIONREPORT_HPP_

#include <fixp/tags.hpp>
#include <fixp/traits.hpp>
namespace fixp
{

class ExecutionReport : public fixp::component
{
public:
	using Base = fixp::component;
	using tag_type = traits::tag_type;
	using amt_type = traits::amt_type;
	using boolean_type = traits::boolean_type;
	using char_type = traits::char_type;
	using currency_type = traits::currency_type;
	using data_type = traits::data_type;
	using exchange_type = traits::exchange_type;
	using float_type = traits::float_type;
	using int_type = traits::int_type;
	using length_type = traits::length_type;
	using localmktdate_type = traits::localmktdate_type;
	using multiplecharvalue_type = traits::multiplecharvalue_type;
	using multiplestringvalue_type = traits::multiplestringvalue_type;
	using percentage_type = traits::percentage_type;
	using price_type = traits::price_type;
	using priceoffset_type = traits::priceoffset_type;
	using qty_type = traits::qty_type;
	using string_type = traits::string_type;
	using utctimestamp_type = traits::utctimestamp_type;

	// observers

	string_type getAccount() { return Base::getField(tags::Account); }
	int_type getAccountType() { return Base::getField(tags::AccountType); }
	amt_type getAccruedInterestAmt() { return Base::getField(tags::AccruedInterestAmt); }
	percentage_type getAccruedInterestRate() { return Base::getField(tags::AccruedInterestRate); }
	int_type getAcctIDSource() { return Base::getField(tags::AcctIDSource); }
	boolean_type getAggressorIndicator() { return Base::getField(tags::AggressorIndicator); }
	string_type getAllocID() { return Base::getField(tags::AllocID); }
	price_type getAvgPx() { return Base::getField(tags::AvgPx); }
	localmktdate_type getBasisFeatureDate() { return Base::getField(tags::BasisFeatureDate); }
	price_type getBasisFeaturePrice() { return Base::getField(tags::BasisFeaturePrice); }
	int_type getBookingType() { return Base::getField(tags::BookingType); }
	char_type getBookingUnit() { return Base::getField(tags::BookingUnit); }
	qty_type getCalculatedCcyLastQty() { return Base::getField(tags::CalculatedCcyLastQty); }
	char_type getCancellationRights() { return Base::getField(tags::CancellationRights); }
	char_type getCashMargin() { return Base::getField(tags::CashMargin); }
	string_type getClOrdID() { return Base::getField(tags::ClOrdID); }
	string_type getClOrdLinkID() { return Base::getField(tags::ClOrdLinkID); }
	string_type getClearingFeeIndicator() { return Base::getField(tags::ClearingFeeIndicator); }
	string_type getComplianceID() { return Base::getField(tags::ComplianceID); }
	amt_type getConcession() { return Base::getField(tags::Concession); }
	boolean_type getCopyMsgIndicator() { return Base::getField(tags::CopyMsgIndicator); }
	string_type getCrossID() { return Base::getField(tags::CrossID); }
	int_type getCrossType() { return Base::getField(tags::CrossType); }
	qty_type getCumQty() { return Base::getField(tags::CumQty); }
	currency_type getCurrency() { return Base::getField(tags::Currency); }
	boolean_type getCustDirectedOrder() { return Base::getField(tags::CustDirectedOrder); }
	int_type getCustOrderCapacity() { return Base::getField(tags::CustOrderCapacity); }
	multiplestringvalue_type getCustOrderHandlingInst() { return Base::getField(tags::CustOrderHandlingInst); }
	price_type getDayAvgPx() { return Base::getField(tags::DayAvgPx); }
	char_type getDayBookingInst() { return Base::getField(tags::DayBookingInst); }
	qty_type getDayCumQty() { return Base::getField(tags::DayCumQty); }
	qty_type getDayOrderQty() { return Base::getField(tags::DayOrderQty); }
	string_type getDesignation() { return Base::getField(tags::Designation); }
	price_type getDiscretionPrice() { return Base::getField(tags::DiscretionPrice); }
	percentage_type getDividendYield() { return Base::getField(tags::DividendYield); }
	utctimestamp_type getEffectiveTime() { return Base::getField(tags::EffectiveTime); }
	data_type getEncodedText() { return Base::getField(tags::EncodedText); }
	length_type getEncodedTextLen() { return Base::getField(tags::EncodedTextLen); }
	amt_type getEndAccruedInterestAmt() { return Base::getField(tags::EndAccruedInterestAmt); }
	amt_type getEndCash() { return Base::getField(tags::EndCash); }
	localmktdate_type getExDate() { return Base::getField(tags::ExDate); }
	string_type getExecID() { return Base::getField(tags::ExecID); }
	multiplecharvalue_type getExecInst() { return Base::getField(tags::ExecInst); }
	float_type getExecPriceAdjustment() { return Base::getField(tags::ExecPriceAdjustment); }
	char_type getExecPriceType() { return Base::getField(tags::ExecPriceType); }
	string_type getExecRefID() { return Base::getField(tags::ExecRefID); }
	int_type getExecRestatementReason() { return Base::getField(tags::ExecRestatementReason); }
	char_type getExecType() { return Base::getField(tags::ExecType); }
	utctimestamp_type getExecValuationPoint() { return Base::getField(tags::ExecValuationPoint); }
	localmktdate_type getExpireDate() { return Base::getField(tags::ExpireDate); }
	utctimestamp_type getExpireTime() { return Base::getField(tags::ExpireTime); }
	int_type getGTBookingInst() { return Base::getField(tags::GTBookingInst); }
	amt_type getGrossTradeAmt() { return Base::getField(tags::GrossTradeAmt); }
	char_type getHandlInst() { return Base::getField(tags::HandlInst); }
	string_type getHostCrossID() { return Base::getField(tags::HostCrossID); }
	amt_type getInterestAtMaturity() { return Base::getField(tags::InterestAtMaturity); }
	char_type getLastCapacity() { return Base::getField(tags::LastCapacity); }
	priceoffset_type getLastForwardPoints() { return Base::getField(tags::LastForwardPoints); }
	priceoffset_type getLastForwardPoints2() { return Base::getField(tags::LastForwardPoints2); }
	boolean_type getLastFragment() { return Base::getField(tags::LastFragment); }
	int_type getLastLiquidityInd() { return Base::getField(tags::LastLiquidityInd); }
	exchange_type getLastMkt() { return Base::getField(tags::LastMkt); }
	price_type getLastParPx() { return Base::getField(tags::LastParPx); }
	price_type getLastPx() { return Base::getField(tags::LastPx); }
	qty_type getLastQty() { return Base::getField(tags::LastQty); }
	boolean_type getLastRptRequested() { return Base::getField(tags::LastRptRequested); }
	price_type getLastSpotRate() { return Base::getField(tags::LastSpotRate); }
	priceoffset_type getLastSwapPoints() { return Base::getField(tags::LastSwapPoints); }
	qty_type getLeavesQty() { return Base::getField(tags::LeavesQty); }
	string_type getListID() { return Base::getField(tags::ListID); }
	char_type getLotType() { return Base::getField(tags::LotType); }
	boolean_type getManualOrderIndicator() { return Base::getField(tags::ManualOrderIndicator); }
	string_type getMassStatusReqID() { return Base::getField(tags::MassStatusReqID); }
	qty_type getMatchIncrement() { return Base::getField(tags::MatchIncrement); }
	string_type getMatchType() { return Base::getField(tags::MatchType); }
	qty_type getMaxFloor() { return Base::getField(tags::MaxFloor); }
	int_type getMaxPriceLevels() { return Base::getField(tags::MaxPriceLevels); }
	qty_type getMaxShow() { return Base::getField(tags::MaxShow); }
	qty_type getMinQty() { return Base::getField(tags::MinQty); }
	char_type getMoneyLaunderingStatus() { return Base::getField(tags::MoneyLaunderingStatus); }
	char_type getMultiLegReportingType() { return Base::getField(tags::MultiLegReportingType); }
	amt_type getNetMoney() { return Base::getField(tags::NetMoney); }
	int_type getNumDaysInterest() { return Base::getField(tags::NumDaysInterest); }
	int_type getOrdRejReason() { return Base::getField(tags::OrdRejReason); }
	char_type getOrdStatus() { return Base::getField(tags::OrdStatus); }
	string_type getOrdStatusReqID() { return Base::getField(tags::OrdStatusReqID); }
	char_type getOrdType() { return Base::getField(tags::OrdType); }
	char_type getOrderCapacity() { return Base::getField(tags::OrderCapacity); }
	char_type getOrderCategory() { return Base::getField(tags::OrderCategory); }
	int_type getOrderHandlingInstSource() { return Base::getField(tags::OrderHandlingInstSource); }
	string_type getOrderID() { return Base::getField(tags::OrderID); }
	qty_type getOrderQty2() { return Base::getField(tags::OrderQty2); }
	multiplecharvalue_type getOrderRestrictions() { return Base::getField(tags::OrderRestrictions); }
	string_type getOrigClOrdID() { return Base::getField(tags::OrigClOrdID); }
	string_type getOrigCrossID() { return Base::getField(tags::OrigCrossID); }
	percentage_type getParticipationRate() { return Base::getField(tags::ParticipationRate); }
	price_type getPeggedPrice() { return Base::getField(tags::PeggedPrice); }
	price_type getPeggedRefPrice() { return Base::getField(tags::PeggedRefPrice); }
	char_type getPositionEffect() { return Base::getField(tags::PositionEffect); }
	boolean_type getPreTradeAnonymity() { return Base::getField(tags::PreTradeAnonymity); }
	char_type getPreallocMethod() { return Base::getField(tags::PreallocMethod); }
	price_type getPrice() { return Base::getField(tags::Price); }
	float_type getPriceDelta() { return Base::getField(tags::PriceDelta); }
	priceoffset_type getPriceImprovement() { return Base::getField(tags::PriceImprovement); }
	char_type getPriceProtectionScope() { return Base::getField(tags::PriceProtectionScope); }
	int_type getPriceType() { return Base::getField(tags::PriceType); }
	int_type getPriorityIndicator() { return Base::getField(tags::PriorityIndicator); }
	int_type getQtyType() { return Base::getField(tags::QtyType); }
	string_type getQuoteRespID() { return Base::getField(tags::QuoteRespID); }
	string_type getReceivedDeptID() { return Base::getField(tags::ReceivedDeptID); }
	string_type getRegistID() { return Base::getField(tags::RegistID); }
	boolean_type getReportToExch() { return Base::getField(tags::ReportToExch); }
	float_type getRiskFreeRate() { return Base::getField(tags::RiskFreeRate); }
	string_type getSecondaryClOrdID() { return Base::getField(tags::SecondaryClOrdID); }
	string_type getSecondaryExecID() { return Base::getField(tags::SecondaryExecID); }
	string_type getSecondaryOrderID() { return Base::getField(tags::SecondaryOrderID); }
	amt_type getSettlCurrAmt() { return Base::getField(tags::SettlCurrAmt); }
	float_type getSettlCurrFxRate() { return Base::getField(tags::SettlCurrFxRate); }
	char_type getSettlCurrFxRateCalc() { return Base::getField(tags::SettlCurrFxRateCalc); }
	currency_type getSettlCurrency() { return Base::getField(tags::SettlCurrency); }
	localmktdate_type getSettlDate() { return Base::getField(tags::SettlDate); }
	localmktdate_type getSettlDate2() { return Base::getField(tags::SettlDate2); }
	string_type getSettlType() { return Base::getField(tags::SettlType); }
	char_type getSide() { return Base::getField(tags::Side); }
	boolean_type getSolicitedFlag() { return Base::getField(tags::SolicitedFlag); }
	amt_type getStartCash() { return Base::getField(tags::StartCash); }
	price_type getStopPx() { return Base::getField(tags::StopPx); }
	int_type getTargetStrategy() { return Base::getField(tags::TargetStrategy); }
	string_type getTargetStrategyParameters() { return Base::getField(tags::TargetStrategyParameters); }
	float_type getTargetStrategyPerformance() { return Base::getField(tags::TargetStrategyPerformance); }
	string_type getText() { return Base::getField(tags::Text); }
	string_type getTimeBracket() { return Base::getField(tags::TimeBracket); }
	char_type getTimeInForce() { return Base::getField(tags::TimeInForce); }
	float_type getTimeToExpiration() { return Base::getField(tags::TimeToExpiration); }
	int_type getTotNoFills() { return Base::getField(tags::TotNoFills); }
	int_type getTotNumReports() { return Base::getField(tags::TotNumReports); }
	amt_type getTotalTakedown() { return Base::getField(tags::TotalTakedown); }
	localmktdate_type getTradeDate() { return Base::getField(tags::TradeDate); }
	localmktdate_type getTradeOriginationDate() { return Base::getField(tags::TradeOriginationDate); }
	boolean_type getTradedFlatSwitch() { return Base::getField(tags::TradedFlatSwitch); }
	string_type getTradingSessionID() { return Base::getField(tags::TradingSessionID); }
	string_type getTradingSessionSubID() { return Base::getField(tags::TradingSessionSubID); }
	utctimestamp_type getTransBkdTime() { return Base::getField(tags::TransBkdTime); }
	utctimestamp_type getTransactTime() { return Base::getField(tags::TransactTime); }
	string_type getTrdMatchID() { return Base::getField(tags::TrdMatchID); }
	price_type getUnderlyingLastPx() { return Base::getField(tags::UnderlyingLastPx); }
	qty_type getUnderlyingLastQty() { return Base::getField(tags::UnderlyingLastQty); }
	float_type getVolatility() { return Base::getField(tags::Volatility); }
	boolean_type getWorkingIndicator() { return Base::getField(tags::WorkingIndicator); }

	// modifiers 

	void setAccount(string_type Account) { Base::setField(tags::Account, Account); }
	void setAccountType(int_type AccountType) { Base::setField(tags::AccountType, AccountType); }
	void setAccruedInterestAmt(amt_type AccruedInterestAmt) { Base::setField(tags::AccruedInterestAmt, AccruedInterestAmt); }
	void setAccruedInterestRate(percentage_type AccruedInterestRate) { Base::setField(tags::AccruedInterestRate, AccruedInterestRate); }
	void setAcctIDSource(int_type AcctIDSource) { Base::setField(tags::AcctIDSource, AcctIDSource); }
	void setAggressorIndicator(boolean_type AggressorIndicator) { Base::setField(tags::AggressorIndicator, AggressorIndicator); }
	void setAllocID(string_type AllocID) { Base::setField(tags::AllocID, AllocID); }
	void setAvgPx(price_type AvgPx) { Base::setField(tags::AvgPx, AvgPx); }
	void setBasisFeatureDate(localmktdate_type BasisFeatureDate) { Base::setField(tags::BasisFeatureDate, BasisFeatureDate); }
	void setBasisFeaturePrice(price_type BasisFeaturePrice) { Base::setField(tags::BasisFeaturePrice, BasisFeaturePrice); }
	void setBookingType(int_type BookingType) { Base::setField(tags::BookingType, BookingType); }
	void setBookingUnit(char_type BookingUnit) { Base::setField(tags::BookingUnit, BookingUnit); }
	void setCalculatedCcyLastQty(qty_type CalculatedCcyLastQty) { Base::setField(tags::CalculatedCcyLastQty, CalculatedCcyLastQty); }
	void setCancellationRights(char_type CancellationRights) { Base::setField(tags::CancellationRights, CancellationRights); }
	void setCashMargin(char_type CashMargin) { Base::setField(tags::CashMargin, CashMargin); }
	void setClOrdID(string_type ClOrdID) { Base::setField(tags::ClOrdID, ClOrdID); }
	void setClOrdLinkID(string_type ClOrdLinkID) { Base::setField(tags::ClOrdLinkID, ClOrdLinkID); }
	void setClearingFeeIndicator(string_type ClearingFeeIndicator) { Base::setField(tags::ClearingFeeIndicator, ClearingFeeIndicator); }
	void setComplianceID(string_type ComplianceID) { Base::setField(tags::ComplianceID, ComplianceID); }
	void setConcession(amt_type Concession) { Base::setField(tags::Concession, Concession); }
	void setCopyMsgIndicator(boolean_type CopyMsgIndicator) { Base::setField(tags::CopyMsgIndicator, CopyMsgIndicator); }
	void setCrossID(string_type CrossID) { Base::setField(tags::CrossID, CrossID); }
	void setCrossType(int_type CrossType) { Base::setField(tags::CrossType, CrossType); }
	void setCumQty(qty_type CumQty) { Base::setField(tags::CumQty, CumQty); }
	void setCurrency(currency_type Currency) { Base::setField(tags::Currency, Currency); }
	void setCustDirectedOrder(boolean_type CustDirectedOrder) { Base::setField(tags::CustDirectedOrder, CustDirectedOrder); }
	void setCustOrderCapacity(int_type CustOrderCapacity) { Base::setField(tags::CustOrderCapacity, CustOrderCapacity); }
	void setCustOrderHandlingInst(multiplestringvalue_type CustOrderHandlingInst) { Base::setField(tags::CustOrderHandlingInst, CustOrderHandlingInst); }
	void setDayAvgPx(price_type DayAvgPx) { Base::setField(tags::DayAvgPx, DayAvgPx); }
	void setDayBookingInst(char_type DayBookingInst) { Base::setField(tags::DayBookingInst, DayBookingInst); }
	void setDayCumQty(qty_type DayCumQty) { Base::setField(tags::DayCumQty, DayCumQty); }
	void setDayOrderQty(qty_type DayOrderQty) { Base::setField(tags::DayOrderQty, DayOrderQty); }
	void setDesignation(string_type Designation) { Base::setField(tags::Designation, Designation); }
	void setDiscretionPrice(price_type DiscretionPrice) { Base::setField(tags::DiscretionPrice, DiscretionPrice); }
	void setDividendYield(percentage_type DividendYield) { Base::setField(tags::DividendYield, DividendYield); }
	void setEffectiveTime(utctimestamp_type EffectiveTime) { Base::setField(tags::EffectiveTime, EffectiveTime); }
	void setEncodedText(data_type EncodedText) { Base::setField(tags::EncodedText, EncodedText); }
	void setEncodedTextLen(length_type EncodedTextLen) { Base::setField(tags::EncodedTextLen, EncodedTextLen); }
	void setEndAccruedInterestAmt(amt_type EndAccruedInterestAmt) { Base::setField(tags::EndAccruedInterestAmt, EndAccruedInterestAmt); }
	void setEndCash(amt_type EndCash) { Base::setField(tags::EndCash, EndCash); }
	void setExDate(localmktdate_type ExDate) { Base::setField(tags::ExDate, ExDate); }
	void setExecID(string_type ExecID) { Base::setField(tags::ExecID, ExecID); }
	void setExecInst(multiplecharvalue_type ExecInst) { Base::setField(tags::ExecInst, ExecInst); }
	void setExecPriceAdjustment(float_type ExecPriceAdjustment) { Base::setField(tags::ExecPriceAdjustment, ExecPriceAdjustment); }
	void setExecPriceType(char_type ExecPriceType) { Base::setField(tags::ExecPriceType, ExecPriceType); }
	void setExecRefID(string_type ExecRefID) { Base::setField(tags::ExecRefID, ExecRefID); }
	void setExecRestatementReason(int_type ExecRestatementReason) { Base::setField(tags::ExecRestatementReason, ExecRestatementReason); }
	void setExecType(char_type ExecType) { Base::setField(tags::ExecType, ExecType); }
	void setExecValuationPoint(utctimestamp_type ExecValuationPoint) { Base::setField(tags::ExecValuationPoint, ExecValuationPoint); }
	void setExpireDate(localmktdate_type ExpireDate) { Base::setField(tags::ExpireDate, ExpireDate); }
	void setExpireTime(utctimestamp_type ExpireTime) { Base::setField(tags::ExpireTime, ExpireTime); }
	void setGTBookingInst(int_type GTBookingInst) { Base::setField(tags::GTBookingInst, GTBookingInst); }
	void setGrossTradeAmt(amt_type GrossTradeAmt) { Base::setField(tags::GrossTradeAmt, GrossTradeAmt); }
	void setHandlInst(char_type HandlInst) { Base::setField(tags::HandlInst, HandlInst); }
	void setHostCrossID(string_type HostCrossID) { Base::setField(tags::HostCrossID, HostCrossID); }
	void setInterestAtMaturity(amt_type InterestAtMaturity) { Base::setField(tags::InterestAtMaturity, InterestAtMaturity); }
	void setLastCapacity(char_type LastCapacity) { Base::setField(tags::LastCapacity, LastCapacity); }
	void setLastForwardPoints(priceoffset_type LastForwardPoints) { Base::setField(tags::LastForwardPoints, LastForwardPoints); }
	void setLastForwardPoints2(priceoffset_type LastForwardPoints2) { Base::setField(tags::LastForwardPoints2, LastForwardPoints2); }
	void setLastFragment(boolean_type LastFragment) { Base::setField(tags::LastFragment, LastFragment); }
	void setLastLiquidityInd(int_type LastLiquidityInd) { Base::setField(tags::LastLiquidityInd, LastLiquidityInd); }
	void setLastMkt(exchange_type LastMkt) { Base::setField(tags::LastMkt, LastMkt); }
	void setLastParPx(price_type LastParPx) { Base::setField(tags::LastParPx, LastParPx); }
	void setLastPx(price_type LastPx) { Base::setField(tags::LastPx, LastPx); }
	void setLastQty(qty_type LastQty) { Base::setField(tags::LastQty, LastQty); }
	void setLastRptRequested(boolean_type LastRptRequested) { Base::setField(tags::LastRptRequested, LastRptRequested); }
	void setLastSpotRate(price_type LastSpotRate) { Base::setField(tags::LastSpotRate, LastSpotRate); }
	void setLastSwapPoints(priceoffset_type LastSwapPoints) { Base::setField(tags::LastSwapPoints, LastSwapPoints); }
	void setLeavesQty(qty_type LeavesQty) { Base::setField(tags::LeavesQty, LeavesQty); }
	void setListID(string_type ListID) { Base::setField(tags::ListID, ListID); }
	void setLotType(char_type LotType) { Base::setField(tags::LotType, LotType); }
	void setManualOrderIndicator(boolean_type ManualOrderIndicator) { Base::setField(tags::ManualOrderIndicator, ManualOrderIndicator); }
	void setMassStatusReqID(string_type MassStatusReqID) { Base::setField(tags::MassStatusReqID, MassStatusReqID); }
	void setMatchIncrement(qty_type MatchIncrement) { Base::setField(tags::MatchIncrement, MatchIncrement); }
	void setMatchType(string_type MatchType) { Base::setField(tags::MatchType, MatchType); }
	void setMaxFloor(qty_type MaxFloor) { Base::setField(tags::MaxFloor, MaxFloor); }
	void setMaxPriceLevels(int_type MaxPriceLevels) { Base::setField(tags::MaxPriceLevels, MaxPriceLevels); }
	void setMaxShow(qty_type MaxShow) { Base::setField(tags::MaxShow, MaxShow); }
	void setMinQty(qty_type MinQty) { Base::setField(tags::MinQty, MinQty); }
	void setMoneyLaunderingStatus(char_type MoneyLaunderingStatus) { Base::setField(tags::MoneyLaunderingStatus, MoneyLaunderingStatus); }
	void setMultiLegReportingType(char_type MultiLegReportingType) { Base::setField(tags::MultiLegReportingType, MultiLegReportingType); }
	void setNetMoney(amt_type NetMoney) { Base::setField(tags::NetMoney, NetMoney); }
	void setNumDaysInterest(int_type NumDaysInterest) { Base::setField(tags::NumDaysInterest, NumDaysInterest); }
	void setOrdRejReason(int_type OrdRejReason) { Base::setField(tags::OrdRejReason, OrdRejReason); }
	void setOrdStatus(char_type OrdStatus) { Base::setField(tags::OrdStatus, OrdStatus); }
	void setOrdStatusReqID(string_type OrdStatusReqID) { Base::setField(tags::OrdStatusReqID, OrdStatusReqID); }
	void setOrdType(char_type OrdType) { Base::setField(tags::OrdType, OrdType); }
	void setOrderCapacity(char_type OrderCapacity) { Base::setField(tags::OrderCapacity, OrderCapacity); }
	void setOrderCategory(char_type OrderCategory) { Base::setField(tags::OrderCategory, OrderCategory); }
	void setOrderHandlingInstSource(int_type OrderHandlingInstSource) { Base::setField(tags::OrderHandlingInstSource, OrderHandlingInstSource); }
	void setOrderID(string_type OrderID) { Base::setField(tags::OrderID, OrderID); }
	void setOrderQty2(qty_type OrderQty2) { Base::setField(tags::OrderQty2, OrderQty2); }
	void setOrderRestrictions(multiplecharvalue_type OrderRestrictions) { Base::setField(tags::OrderRestrictions, OrderRestrictions); }
	void setOrigClOrdID(string_type OrigClOrdID) { Base::setField(tags::OrigClOrdID, OrigClOrdID); }
	void setOrigCrossID(string_type OrigCrossID) { Base::setField(tags::OrigCrossID, OrigCrossID); }
	void setParticipationRate(percentage_type ParticipationRate) { Base::setField(tags::ParticipationRate, ParticipationRate); }
	void setPeggedPrice(price_type PeggedPrice) { Base::setField(tags::PeggedPrice, PeggedPrice); }
	void setPeggedRefPrice(price_type PeggedRefPrice) { Base::setField(tags::PeggedRefPrice, PeggedRefPrice); }
	void setPositionEffect(char_type PositionEffect) { Base::setField(tags::PositionEffect, PositionEffect); }
	void setPreTradeAnonymity(boolean_type PreTradeAnonymity) { Base::setField(tags::PreTradeAnonymity, PreTradeAnonymity); }
	void setPreallocMethod(char_type PreallocMethod) { Base::setField(tags::PreallocMethod, PreallocMethod); }
	void setPrice(price_type Price) { Base::setField(tags::Price, Price); }
	void setPriceDelta(float_type PriceDelta) { Base::setField(tags::PriceDelta, PriceDelta); }
	void setPriceImprovement(priceoffset_type PriceImprovement) { Base::setField(tags::PriceImprovement, PriceImprovement); }
	void setPriceProtectionScope(char_type PriceProtectionScope) { Base::setField(tags::PriceProtectionScope, PriceProtectionScope); }
	void setPriceType(int_type PriceType) { Base::setField(tags::PriceType, PriceType); }
	void setPriorityIndicator(int_type PriorityIndicator) { Base::setField(tags::PriorityIndicator, PriorityIndicator); }
	void setQtyType(int_type QtyType) { Base::setField(tags::QtyType, QtyType); }
	void setQuoteRespID(string_type QuoteRespID) { Base::setField(tags::QuoteRespID, QuoteRespID); }
	void setReceivedDeptID(string_type ReceivedDeptID) { Base::setField(tags::ReceivedDeptID, ReceivedDeptID); }
	void setRegistID(string_type RegistID) { Base::setField(tags::RegistID, RegistID); }
	void setReportToExch(boolean_type ReportToExch) { Base::setField(tags::ReportToExch, ReportToExch); }
	void setRiskFreeRate(float_type RiskFreeRate) { Base::setField(tags::RiskFreeRate, RiskFreeRate); }
	void setSecondaryClOrdID(string_type SecondaryClOrdID) { Base::setField(tags::SecondaryClOrdID, SecondaryClOrdID); }
	void setSecondaryExecID(string_type SecondaryExecID) { Base::setField(tags::SecondaryExecID, SecondaryExecID); }
	void setSecondaryOrderID(string_type SecondaryOrderID) { Base::setField(tags::SecondaryOrderID, SecondaryOrderID); }
	void setSettlCurrAmt(amt_type SettlCurrAmt) { Base::setField(tags::SettlCurrAmt, SettlCurrAmt); }
	void setSettlCurrFxRate(float_type SettlCurrFxRate) { Base::setField(tags::SettlCurrFxRate, SettlCurrFxRate); }
	void setSettlCurrFxRateCalc(char_type SettlCurrFxRateCalc) { Base::setField(tags::SettlCurrFxRateCalc, SettlCurrFxRateCalc); }
	void setSettlCurrency(currency_type SettlCurrency) { Base::setField(tags::SettlCurrency, SettlCurrency); }
	void setSettlDate(localmktdate_type SettlDate) { Base::setField(tags::SettlDate, SettlDate); }
	void setSettlDate2(localmktdate_type SettlDate2) { Base::setField(tags::SettlDate2, SettlDate2); }
	void setSettlType(string_type SettlType) { Base::setField(tags::SettlType, SettlType); }
	void setSide(char_type Side) { Base::setField(tags::Side, Side); }
	void setSolicitedFlag(boolean_type SolicitedFlag) { Base::setField(tags::SolicitedFlag, SolicitedFlag); }
	void setStartCash(amt_type StartCash) { Base::setField(tags::StartCash, StartCash); }
	void setStopPx(price_type StopPx) { Base::setField(tags::StopPx, StopPx); }
	void setTargetStrategy(int_type TargetStrategy) { Base::setField(tags::TargetStrategy, TargetStrategy); }
	void setTargetStrategyParameters(string_type TargetStrategyParameters) { Base::setField(tags::TargetStrategyParameters, TargetStrategyParameters); }
	void setTargetStrategyPerformance(float_type TargetStrategyPerformance) { Base::setField(tags::TargetStrategyPerformance, TargetStrategyPerformance); }
	void setText(string_type Text) { Base::setField(tags::Text, Text); }
	void setTimeBracket(string_type TimeBracket) { Base::setField(tags::TimeBracket, TimeBracket); }
	void setTimeInForce(char_type TimeInForce) { Base::setField(tags::TimeInForce, TimeInForce); }
	void setTimeToExpiration(float_type TimeToExpiration) { Base::setField(tags::TimeToExpiration, TimeToExpiration); }
	void setTotNoFills(int_type TotNoFills) { Base::setField(tags::TotNoFills, TotNoFills); }
	void setTotNumReports(int_type TotNumReports) { Base::setField(tags::TotNumReports, TotNumReports); }
	void setTotalTakedown(amt_type TotalTakedown) { Base::setField(tags::TotalTakedown, TotalTakedown); }
	void setTradeDate(localmktdate_type TradeDate) { Base::setField(tags::TradeDate, TradeDate); }
	void setTradeOriginationDate(localmktdate_type TradeOriginationDate) { Base::setField(tags::TradeOriginationDate, TradeOriginationDate); }
	void setTradedFlatSwitch(boolean_type TradedFlatSwitch) { Base::setField(tags::TradedFlatSwitch, TradedFlatSwitch); }
	void setTradingSessionID(string_type TradingSessionID) { Base::setField(tags::TradingSessionID, TradingSessionID); }
	void setTradingSessionSubID(string_type TradingSessionSubID) { Base::setField(tags::TradingSessionSubID, TradingSessionSubID); }
	void setTransBkdTime(utctimestamp_type TransBkdTime) { Base::setField(tags::TransBkdTime, TransBkdTime); }
	void setTransactTime(utctimestamp_type TransactTime) { Base::setField(tags::TransactTime, TransactTime); }
	void setTrdMatchID(string_type TrdMatchID) { Base::setField(tags::TrdMatchID, TrdMatchID); }
	void setUnderlyingLastPx(price_type UnderlyingLastPx) { Base::setField(tags::UnderlyingLastPx, UnderlyingLastPx); }
	void setUnderlyingLastQty(qty_type UnderlyingLastQty) { Base::setField(tags::UnderlyingLastQty, UnderlyingLastQty); }
	void setVolatility(float_type Volatility) { Base::setField(tags::Volatility, Volatility); }
	void setWorkingIndicator(boolean_type WorkingIndicator) { Base::setField(tags::WorkingIndicator, WorkingIndicator); }
};
}
#endif
